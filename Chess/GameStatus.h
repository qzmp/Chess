#pragma once

//#include <vector>
//#include "Piece.h"
#include "Square.h"

class Square;
class Piece;
enum Color;

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

	bool isControlledByWhite(int x, int y);
	bool isControlledByBlack(int x, int y);
};

