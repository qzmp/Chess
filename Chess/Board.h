#pragma once

//#include <vector>
#include "Piece.h"

using namespace std;

class Board
{
	
private:
	vector<vector<Piece*>> board;
	double rating;
	Color currentPlayer;	

public:
	Board();
	Board(Board& otherBoard);
	~Board();

	void startSetup();
	bool isKingChecked();
	
	vector<vector<Piece*>>& getBoard();
};

