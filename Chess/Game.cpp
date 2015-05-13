#include "Game.h"
#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}

int main()
{
	GameStatus board = GameStatus();
	board.startSetup();
	board.generateMoves();
	cout << "test";
}
