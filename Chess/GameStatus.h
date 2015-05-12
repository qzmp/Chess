#pragma once

#include "Piece.h"


class Piece;
enum Color;

using namespace std;

class GameStatus
{
	
private:
	vector<vector<Piece*>> board;
	double rating;
	Color currentPlayer;

public:
	GameStatus();
	GameStatus(GameStatus& otherBoard);
	~GameStatus();
	
	void startSetup();
	bool isChecked();
	
	vector<vector<Piece*>>& getBoard();

	list<GameStatus> generateMoves();

	Color getCurrentPlayer();
};

