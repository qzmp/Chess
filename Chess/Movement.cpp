#include "Movement.h"


void Movement::moveUp(vector<vector<Square>> & board, int x, int y)
{
	board[y - 1][x].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveDown(vector<vector<Square>> & board, int x, int y)
{
	board[y + 1][x].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveRight(vector<vector<Square>> & board, int x, int y)
{
	board[y][x + 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveLeft(vector<vector<Square>> & board, int x, int y)
{
	board[y][x - 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveUpRight(vector<vector<Square>> & board, int x, int y)
{
	board[y - 1][x + 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveUpLeft(vector<vector<Square>> & board, int x, int y)
{
	board[y - 1][x - 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveDownRight(vector<vector<Square>> & board, int x, int y)
{
	board[y + 1][x + 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

void Movement::moveDownLeft(vector<vector<Square>> & board, int x, int y)
{
	board[y + 1][x - 1].setPiece(*board[y][x].getPiece());
	board[y][x].removePiece();
}

