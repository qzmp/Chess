#pragma once

//#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"


class Piece;
/*
class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;
enum Color;
*/

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

