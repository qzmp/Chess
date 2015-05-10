#pragma once

//#include <vector>
#include "Piece.h"
#include "Square.h"

using namespace std;

class GameStatus
{
	
private:
	vector<vector<Square>> board;
	double rating;
	Color currentPlayer;	

public:
	GameStatus();
	GameStatus(GameStatus& otherBoard);
	~GameStatus();

	void startSetup();
	bool isChecked();
	
	vector<vector<Square>>& getBoard();

	list<GameStatus> generateMoves();
};

