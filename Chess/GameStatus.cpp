#include "GameStatus.h"


GameStatus::GameStatus()
{
	board.resize(8);
	for (int i = 0; i < 8; i++)
		board[i].resize(8);
}

GameStatus::GameStatus(GameStatus& otherGameStatus)
{
	this->board = otherGameStatus.getBoard();
}

GameStatus::~GameStatus()
{
}

void GameStatus::startSetup(){

	board[0][0].setPiece(*new Piece(Rook, Black));
	board[0][1].setPiece(*new Piece(Knight, Black));
	board[0][2].setPiece(*new Piece(Bishop, Black));
	board[0][3].setPiece(*new Piece(Queen, Black));
	board[0][4].setPiece(*new Piece(King, Black));
	board[0][5].setPiece(*new Piece(Bishop, Black));
	board[0][6].setPiece(*new Piece(Knight, Black));
	board[0][7].setPiece(*new Piece(Rook, Black));
	for (int i = 0; i < 8; i++)
	{
		board[1][i].setPiece(*new Piece(Pawn, Black));
	}

	board[7][0].setPiece(*new Piece(Rook, White));
	board[7][1].setPiece(*new Piece(Knight, White));
	board[7][2].setPiece(*new Piece(Bishop, White));
	board[7][3].setPiece(*new Piece(Queen, White));
	board[7][4].setPiece(*new Piece(King, White));
	board[7][5].setPiece(*new Piece(Bishop, White));
	board[7][6].setPiece(*new Piece(Knight, White));
	board[7][7].setPiece(*new Piece(Rook, White));
	for (int i = 0; i < 8; i++)
	{
		board[6][i].setPiece(*new Piece(Pawn, White));
	}
}

vector<vector<Square>>& GameStatus::getBoard()
{
	return board;
}

list<GameStatus> GameStatus::generateMoves()
{
	list<GameStatus> moves;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j].getPiece() != nullptr)
				moves.splice(moves.end(), this->board[i][j].getPiece()->generateMoves(*this));
		}
	}
	return moves;
}