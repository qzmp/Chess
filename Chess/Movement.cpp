#include "Movement.h"


void Movement::moveUp(vector<vector<Piece*>> & board, int x, int y)
{
	board[y - 1][x] = (board[y][x]);
	board[y][x] = nullptr;
}

void Movement::moveDown(vector<vector<Piece*>> & board, int x, int y)
{
	board[y + 1][x] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveRight(vector<vector<Piece*>> & board, int x, int y)
{
	board[y][x + 1] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveLeft(vector<vector<Piece*>> & board, int x, int y)
{
	board[y][x - 1] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveUpRight(vector<vector<Piece*>> & board, int x, int y)
{
	board[y - 1][x + 1] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveUpLeft(vector<vector<Piece*>> & board, int x, int y)
{
	board[y - 1][x - 1] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveDownRight(vector<vector<Piece*>> & board, int x, int y)
{
	board[y + 1][x + 1] = board[y][x];
	board[y][x] = nullptr;
}

void Movement::moveDownLeft(vector<vector<Piece*>> & board, int x, int y)
{
	board[y + 1][x - 1] = board[y][x];
	board[y][x] = nullptr;
}

