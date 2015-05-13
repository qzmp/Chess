#include "King.h"


King::King(Color color, int x, int y) : Piece(color, x, y)
{
	
	pieceSquareTable =
	{ { -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -20, -30, -30, -40, -40, -30, -30, -20 },
	{ -10, -20, -20, -20, -20, -20, -20, -10 },
	{ 20, 20, 0, 0, 0, 0, 20, 20 },
	{ 20, 30, 10, 0, 0, 10, 30, 20 } };

	if (color == Black){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
	
}


King::~King()
{
}

list<Movement> King::generateMoves(GameStatus& currentStatus){

	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	//top left
	int checkedX = x - 1;
	int checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top
	checkedX = x;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top right
	checkedX = x + 1;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//right
	checkedX = x + 1;
	checkedY = y;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom right
	checkedX = x + 1;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom
	checkedX = x;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom left
	checkedX = x - 1;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//left
	checkedX = x - 1;
	checkedY = y;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	return moves;
}

bool King::isCheckedDiagonally(GameStatus& currentStatus)
{
	int x = location.getX();
	int y = location.getY();

	PieceType encounteredPiece;

	//top left
	int checkedX = x - 1;
	int checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Bishop || encounteredPiece == PieceType::King || (this->color == White && encounteredPiece == Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		checkedY = checkedY - 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Bishop)
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
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Bishop || encounteredPiece == PieceType::King || (this->color == White && encounteredPiece == Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		checkedY = checkedY - 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Bishop)
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
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Bishop || encounteredPiece == PieceType::King || (this->color == Black && encounteredPiece == Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		checkedY = checkedY + 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Bishop)
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
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Bishop || encounteredPiece == PieceType::King || (this->color == Black && encounteredPiece == Pawn))
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		checkedY = checkedY + 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Bishop)
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

bool King::isCheckedVertically(GameStatus& currentStatus)
{
	int x = location.getX();
	int y = location.getY();

	PieceType encounteredPiece;

	//top
	int checkedX = x;
	int checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Rook || encounteredPiece == PieceType::King)
			{
				return true;
			}
		}
		checkedY = checkedY - 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Rook)
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
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Rook || encounteredPiece == PieceType::King)
			{
				return true;
			}
		}
		checkedY = checkedY + 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Rook)
				{
					return true;
				}
			}
			checkedY = checkedY + 1;
		}
	}
	return false;
}

bool King::isCheckedHorizontally(GameStatus& currentStatus)
{
	int x = location.getX();
	int y = location.getY();

	//left
	int checkedX = x - 1;
	int checkedY = y;

	PieceType encounteredPiece;

	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Rook || encounteredPiece == PieceType::King)
			{
				return true;
			}
		}
		checkedX = checkedX - 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Rook)
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
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
			if (encounteredPiece == Queen || encounteredPiece == Rook || encounteredPiece == PieceType::King)
			{
				return true;
			}
		}
		checkedX = checkedX + 1;
		while (currentStatus.canPlace(checkedX, checkedY, this->color))
		{
			if (currentStatus.isOccupied(checkedX, checkedY))
			{
				encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
				if (encounteredPiece == Queen || encounteredPiece == Rook)
				{
					return true;
				}
			}
			checkedX = checkedX + 1;
		}
	}
	return false;
}

bool King::isCheckedByKnight(GameStatus& currentStatus)
{
	int x = location.getX();
	int y = location.getY();

	PieceType encounteredPiece;

	//top top left
	int checkedX = x - 1;
	int checkedY = y - 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//bottom top left
	checkedX = x - 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//top top right
	checkedX = x + 1;
	checkedY = y - 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//bottom top right
	checkedX = x + 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//top bottom right
	checkedX = x + 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//bottom bottom right
	checkedX = x + 1;
	checkedY = y + 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//top bottom left
	checkedX = x - 1;
	checkedY = y + 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	//bottom bottom left
	checkedX = x - 2;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color) && currentStatus.isOccupied(checkedX, checkedY))
	{
		encounteredPiece = currentStatus.getBoard()[checkedY][checkedX]->getPieceType();
		if (encounteredPiece == Knight)
		{
			return true;
		}
	}

	return false;
}


bool King::isChecked(GameStatus& currentStatus)
{
	return (isCheckedByKnight(currentStatus) || isCheckedDiagonally(currentStatus) || isCheckedHorizontally(currentStatus) || isCheckedVertically(currentStatus));
}

Piece::PieceType King::getPieceType()
{
	return PieceType::King;
}

int King::getValue()
{
	return 20000 + pieceSquareTable[location.getY()][location.getY()];
}