#include "Board.h"


Board::Board()
{
	board.resize(8);
	for (int i = 0; i < 8; i++)
		board[i].resize(8);
}

Board::Board(Board& otherBoard)
{
	board = otherBoard.getBoard();
}

Board::~Board()
{
}

void Board::startSetup(){

	board[0][0] = new Piece(Rook, Black);
	board[0][1] = new Piece(Knight, Black);
	board[0][2] = new Piece(Bishop, Black);
	board[0][3] = new Piece(Queen, Black);
	board[0][4] = new Piece(King, Black);
	board[0][5] = new Piece(Bishop, Black);
	board[0][6] = new Piece(Knight, Black);
	board[0][7] = new Piece(Rook, Black);
	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Piece(Pawn, Black);
	}

	board[7][0] = new Piece(Rook, White);
	board[7][1] = new Piece(Knight, White);
	board[7][2] = new Piece(Bishop, White);
	board[7][3] = new Piece(Queen, White);
	board[7][4] = new Piece(King, White);
	board[7][5] = new Piece(Bishop, White);
	board[7][6] = new Piece(Knight, White);
	board[7][7] = new Piece(Rook, White);
	for (int i = 0; i < 8; i++)
	{
		board[6][i] = new Piece(Pawn, White);
	}
}

vector<vector<Piece*>>& Board::getBoard()
{
	return board;
}