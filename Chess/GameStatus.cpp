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
	this->currentPlayer = otherGameStatus.currentPlayer;
}

GameStatus::~GameStatus()
{
}

void GameStatus::startSetup(){
	
	board[0][0] = new Rook(Black, 0, 0);
	board[0][1] = new Knight(Black, 1, 0);
	board[0][2] = new Bishop(Black, 2, 0);
	board[0][3] = new Queen(Black, 3, 0);
	board[0][4] = new King(Black, 4, 0);
	board[0][5] = new Bishop(Black, 5, 0);
	board[0][6] = new Knight(Black, 6, 0);
	board[0][7] = new Rook(Black, 7, 0);
	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Pawn(Black, i, 1);
	}

	board[7][0] = new Rook(White, 0, 7);
	board[7][1] = new Knight(White, 1, 7);
	board[7][2] = new Bishop(White, 2, 7);
	board[7][3] = new Queen(White, 3, 7);
	board[7][4] = new King(White, 4, 7);
	board[7][5] = new Bishop(White, 5, 7);
	board[7][6] = new Knight(White, 6, 7);
	board[7][7] = new Rook(White, 7, 7);
	for (int i = 0; i < 8; i++)
	{
		board[6][i] = new Pawn(White, i, 6);
	}

	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(board[0][i]);
		pieces.push_back(board[1][i]);
		pieces.push_back(board[6][i]);
		pieces.push_back(board[7][i]);
	}
}

vector<vector<Piece*>>& GameStatus::getBoard()
{
	return board;
}

list<Movement> GameStatus::generateMoves()
{
	list<Movement> moves;

	for (list<Piece*>::iterator it = pieces.begin(); it != pieces.end(); it++)
	{
		moves.splice(moves.end(), (*it)->generateMoves(*this));
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

bool GameStatus::isColor(int x, int y, Color color)
{
	return this->board[y][x]->getColor() == color;
}

bool GameStatus::canPlace(int x, int y, Color color)
{
	return (isAvailable(x, y) && (!isOccupied(x, y) || !isColor(x, y, color)));
}