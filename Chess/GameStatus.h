#pragma once

#include "Movement.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"


class Piece;

class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;
enum Color;


using namespace std;

class GameStatus
{
	
private:
	vector<vector<Piece*>> board;
	list<Piece*> pieces;
	double rating;
	Color currentPlayer;

public:
	GameStatus();
	GameStatus(GameStatus& otherBoard);
	~GameStatus();
	
	void startSetup();
	bool isChecked();
	
	vector<vector<Piece*>>& getBoard();

	list<Movement> generateMoves();

	Color getCurrentPlayer();

	bool isAvailable(int x, int y);
	bool isOccupied(int x, int y);
	bool isColor(int x, int y, Color color);
	bool canPlace(int x, int y, Color color);
};

