#include "GameStatus.h"


GameStatus::GameStatus()
{
	board.resize(8);
	for (int i = 0; i < 8; i++)
		board[i].resize(8);
	currentPlayer = Black;
}

GameStatus::~GameStatus()
{
}

void GameStatus::startSetup(){
	this->board = vector<vector<Piece*>>();
	this->pieces = list<Piece*>();
	board.resize(8);
	for (int i = 0; i < 8; i++)
		board[i].resize(8);

	board[0][0] = new Rook(White, 0, 0);
	board[0][1] = new Knight(White, 1, 0);
	board[0][2] = new Bishop(White, 2, 0);
	board[0][3] = new Queen(White, 3, 0);
	board[0][4] = new King(White, 4, 0);
	board[0][5] = new Bishop(White, 5, 0);
	board[0][6] = new Knight(White, 6, 0);
	board[0][7] = new Rook(White, 7, 0);
	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Pawn(White, i, 1);
	}

	board[7][0] = new Rook(Black, 0, 7);
	board[7][1] = new Knight(Black, 1, 7);
	board[7][2] = new Bishop(Black, 2, 7);
	board[7][3] = new Queen(Black, 3, 7);
	board[7][4] = new King(Black, 4, 7);
	board[7][5] = new Bishop(Black, 5, 7);
	board[7][6] = new Knight(Black, 6, 7);
	board[7][7] = new Rook(Black, 7, 7);
	for (int i = 0; i < 8; i++)
	{
		board[6][i] = new Pawn(Black, i, 6);
	}

	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(board[0][i]);
		pieces.push_back(board[1][i]);
		pieces.push_back(board[6][i]);
		pieces.push_back(board[7][i]);
	}
	BlackKing = board[0][4];
	WhiteKing = board[7][4];
}

vector<vector<Piece*>>& GameStatus::getBoard()
{
	return board;
}

Piece& GameStatus::getPiece(Point& location)
{
	return *this->board[location.getY()][location.getX()];
}

list<Movement> GameStatus::generateMoves()
{
	list<Movement> moves;

	for (list<Piece*>::iterator it = pieces.begin(); it != pieces.end(); it++)
	{
		if ((*it)->getColor() == currentPlayer)
		{
			moves.splice(moves.end(), (*it)->generateMoves(*this));
		}
		
	}
	return moves;
}


Color GameStatus::getCurrentPlayer()
{
	return currentPlayer;
}

bool GameStatus::isAvailable(int x, int y)
{
	return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

bool GameStatus::isOccupied(int x, int y)
{
	return this->board[y][x] != nullptr;
}

bool GameStatus::isOccupied(Point location)
{
	return this->board[location.getY()][location.getX()] != nullptr;
}

bool GameStatus::isColor(int x, int y, Color color)
{
	return this->board[y][x]->getColor() == color;
}

bool GameStatus::canPlace(int x, int y, Color color)
{
	return (isAvailable(x, y) && (!isOccupied(x, y) || !isColor(x, y, color)));
}

int GameStatus::rate()
{
	int rating = 0;
	for (list<Piece*>::iterator it = pieces.begin(); it != pieces.end(); it++)
	{
		rating += (*it)->getColor() == currentPlayer ? (*it)->getValue() : -(*it)->getValue();
	}
	return rating;
}

Piece* GameStatus::makeMove(Movement& move, bool& isValid)
{
	
	if (isOccupied(move.getEndPoint()) && getPiece(move.getEndPoint()).getPieceType() == Piece::PieceType::King)
	{
		isValid = false;
		return nullptr;
	}
	else
	{
		Piece* movedPiece = board[move.getStartPoint().getY()][move.getStartPoint().getX()];
		Piece* capturedPiece = board[move.getEndPoint().getY()][move.getEndPoint().getX()];

		board[move.getStartPoint().getY()][move.getStartPoint().getX()]->setLocation(move.getEndPoint().getX(), move.getEndPoint().getY());

		board[move.getEndPoint().getY()][move.getEndPoint().getX()] = board[move.getStartPoint().getY()][move.getStartPoint().getX()];
		board[move.getStartPoint().getY()][move.getStartPoint().getX()] = nullptr;
		if (capturedPiece != nullptr)
		{
			pieces.remove(capturedPiece);
		}

		if ((movedPiece->getColor() == Black && isChecked(*BlackKing)) || (movedPiece->getColor() == White && isChecked(*WhiteKing)))
		{
			board[move.getStartPoint().getY()][move.getStartPoint().getX()] = movedPiece;
			board[move.getEndPoint().getY()][move.getEndPoint().getX()] = capturedPiece;
			movedPiece->setLocation(move.getStartPoint().getX(), move.getStartPoint().getY());
			isValid = false;
			return nullptr;
		}

		movedPiece->setLocation(move.getEndPoint().getX(), move.getEndPoint().getY());
		isValid = true;
		return capturedPiece;
	}
}

void GameStatus::remakeMove(Movement& move, Piece* capturedPiece)
{
	board[move.getEndPoint().getY()][move.getEndPoint().getX()]->setLocation(move.getStartPoint().getX(), move.getStartPoint().getY());

	board[move.getStartPoint().getY()][move.getStartPoint().getX()] = board[move.getEndPoint().getY()][move.getEndPoint().getX()];
	board[move.getEndPoint().getY()][move.getEndPoint().getX()] = capturedPiece;

	if (capturedPiece != nullptr)
	{
		pieces.push_back(capturedPiece);
	}
}

bool GameStatus::isAttackedDiagonally(Piece& piece)
{
	int x = piece.getLocation().getX();
	int y = piece.getLocation().getY();

	Piece::PieceType encounteredPiece;

	//top left
	int checkedX = x - 1;
	int checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop || encounteredPiece == Piece::PieceType::King 
				|| (piece.getColor() == White && encounteredPiece == Piece::PieceType::Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		checkedY = checkedY - 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop)
				{
					return true;
				}
			}
			checkedX = checkedX - 1;
			checkedY = checkedY - 1;
		}
	}

	//top right
	checkedX = x + 1;
	checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop || encounteredPiece == Piece::PieceType::King
				|| (piece.getColor() == White && encounteredPiece == Piece::PieceType::Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		checkedY = checkedY - 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop)
				{
					return true;
				}
			}
			checkedX = checkedX + 1;
			checkedY = checkedY - 1;
		}
	}

	//bottom right
	checkedX = x + 1;
	checkedY = y + 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop || encounteredPiece == Piece::PieceType::King
				|| (piece.getColor() == White && encounteredPiece == Piece::PieceType::Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		checkedY = checkedY + 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop)
				{
					return true;
				}
			}
			checkedX = checkedX + 1;
			checkedY = checkedY + 1;
		}
	}

	//bottom left
	checkedX = x - 1;
	checkedY = y + 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop || encounteredPiece == Piece::PieceType::King
				|| (piece.getColor() == White && encounteredPiece == Piece::PieceType::Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		checkedY = checkedY + 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Bishop)
				{
					return true;
				}
			}
			checkedX = checkedX - 1;
			checkedY = checkedY + 1;
		}
	}

	return false;
}

bool GameStatus::isAttackedVertically(Piece& piece)
{
	int x = piece.getLocation().getX();
	int y = piece.getLocation().getY();

	Piece::PieceType encounteredPiece;

	//top
	int checkedX = x;
	int checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook || encounteredPiece == Piece::PieceType::King)
			{
				return true;
			}
		}
		checkedY = checkedY - 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook)
				{
					return true;
				}
			}
			checkedY = checkedY - 1;
		}
	}

	//bottom
	checkedX = x;
	checkedY = y + 1;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook || encounteredPiece == Piece::PieceType::King)
			{
				return true;
			}
		}
		checkedY = checkedY + 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook)
				{
					return true;
				}
			}
			checkedY = checkedY + 1;
		}
	}
	return false;
}

bool GameStatus::isAttackedHorizontally(Piece& piece)
{
	int x = piece.getLocation().getX();
	int y = piece.getLocation().getY();
	
	Piece::PieceType encounteredPiece;
	
	//left
	int checkedX = x - 1;
	int checkedY = y;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook || encounteredPiece == Piece::PieceType::King)
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook)
				{
					return true;
				}
			}
			checkedX = checkedX - 1;
		}
	}

	//right
	checkedX = x + 1;
	checkedY = y;
	if (canPlace(checkedX, checkedY, piece.getColor()))
	{
		if (isOccupied(checkedX, checkedY))
		{
			encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook || encounteredPiece == Piece::PieceType::King)
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		while (canPlace(checkedX, checkedY, piece.getColor()))
		{
			if (isOccupied(checkedX, checkedY))
			{
				encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Piece::PieceType::Queen || encounteredPiece == Piece::PieceType::Rook)
				{
					return true;
				}
			}
			checkedX = checkedX + 1;
		}
	}
	return false;
}

bool GameStatus::isAttackedByKnight(Piece& piece)
{
	int x = piece.getLocation().getX();
	int y = piece.getLocation().getY();

	Piece::PieceType encounteredPiece;

	//top top left
	int checkedX = x - 1;
	int checkedY = y - 2;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//bottom top left
	checkedX = x - 2;
	checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//top top right
	checkedX = x + 1;
	checkedY = y - 2;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//bottom top right
	checkedX = x + 2;
	checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//top bottom right
	checkedX = x + 2;
	checkedY = y - 1;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//bottom bottom right
	checkedX = x + 1;
	checkedY = y + 2;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//top bottom left
	checkedX = x - 1;
	checkedY = y + 2;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	//bottom bottom left
	checkedX = x - 2;
	checkedY = y + 1;
	if (canPlace(checkedX, checkedY, piece.getColor()) && isOccupied(checkedX, checkedY))
	{
		encounteredPiece = getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Piece::PieceType::Knight)
		{
			return true;
		}
	}

	return false;
}

bool GameStatus::isChecked(Piece& piece)
{
	return (isAttackedByKnight(piece) || isAttackedDiagonally(piece) || isAttackedHorizontally(piece) || isAttackedVertically(piece));
}

Movement& GameStatus::minMax()
{
	Movement bestMove;
	int bestVal = numeric_limits<int>::min();
	int val;
	Piece* capturedPiece;
	bool isValid = true;

	list<Movement> moves = generateMoves();
	for (Movement& m : moves)
	{
		capturedPiece = makeMove(m, isValid);
		if (isValid)
		{
			val = minMax(DEPTH - 1, numeric_limits<int>::min(), numeric_limits<int>::max(), false);
			if (val > bestVal)
			{
				bestVal = val;
				bestMove = m;
			}
			remakeMove(m, capturedPiece);
		}
	}
	return bestMove;
}

int GameStatus::minMax(int depth,int a, int b, bool maximizingPlayer)
{
	int val = 0;
	bool isValid = true;
	Piece* capturedPiece;
	

	if (depth == 0)
	{
		return rate();
	}

	list<Movement> moves = generateMoves();
	if (maximizingPlayer)
	{
		int bestValue = numeric_limits<int>::min();

		for (Movement& m : moves)
		{
			capturedPiece = makeMove(m, isValid);
			if (isValid)
			{
				val = minMax(depth - 1, a, b, !maximizingPlayer); 
				if (bestValue < val)
				{
					bestValue = val;
				}
				if (a < val)
				{
					a = val;
				}

				remakeMove(m, capturedPiece);

				if (b <= a){
					break; //dobrze by bylo cos z tym zrobic
				}
			}
		}
		return bestValue;
	}
	else
	{
		int bestValue = numeric_limits<int>::max();
		for (Movement& m : moves)
		{
			capturedPiece = makeMove(m, isValid);
			if (isValid)
			{
				val = minMax(depth - 1, a, b, !maximizingPlayer);
				if (bestValue > val)
				{
					bestValue = val;
				}
				if (b > val)
				{
					b = val;
				}

				remakeMove(m, capturedPiece);

				if (b <= a){
					break; //dobrze by bylo cos z tym zrobic
				}
			}
		}
		return bestValue;
	}
}