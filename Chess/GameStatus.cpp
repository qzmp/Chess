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
	
	board[0][0] = new Rook(Black);
	board[0][1] = new Knight(Black);
	board[0][2] = new Bishop(Black);
	board[0][3] = new Queen(Black);
	board[0][4] = new King(Black);
	board[0][5] = new Bishop(Black);
	board[0][6] = new Knight(Black);
	board[0][7] = new Rook(Black);
	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Pawn(Black);
	}

	board[7][0] = new Rook(White);
	board[7][1] = new Knight(White);
	board[7][2] = new Bishop(White);
	board[7][3] = new Queen(White);
	board[7][4] = new King(White);
	board[7][5] = new Bishop(White);
	board[7][6] = new Knight(White);
	board[7][7] = new Rook(White);
	for (int i = 0; i < 8; i++)
	{
		board[6][i] = new Pawn(White);
	}
}

vector<vector<Piece*>>& GameStatus::getBoard()
{
	return board;
}

list<Movement> GameStatus::generateMoves()
{
	list<Movement> moves;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] != nullptr)
				moves.splice(moves.end(), this->board[i][j]->generateMoves(*this, j, i));
		}
	}
	return moves;
}

Color GameStatus::getCurrentPlayer()
{
	return currentPlayer;
}