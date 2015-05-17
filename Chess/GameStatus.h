#pragma once

#include <limits>

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
	const int DEPTH = 3;
	vector<vector<Piece*>> board;
	list<Piece*> pieces;
	Piece* WhiteKing;
	Piece* BlackKing;

	int rating;
	Color currentPlayer;

	bool isAttackedDiagonally(Piece& piece);
	bool isAttackedHorizontally(Piece& piece);
	bool isAttackedVertically(Piece& piece);
	bool isAttackedByKnight(Piece& piece);

public:
	GameStatus();
	GameStatus(GameStatus& otherBoard);
	~GameStatus();
	
	void startSetup();
	
	bool isChecked(Piece& piece);
	
	vector<vector<Piece*>>& getBoard();
	Piece& getPiece(Point& location);

	list<Movement> generateMoves();

	Movement Move();

	Color getCurrentPlayer();

	bool isAvailable(int x, int y);
	bool isOccupied(int x, int y);
	bool isOccupied(Point location);
	bool isColor(int x, int y, Color color);
	bool canPlace(int x, int y, Color color);

	int rate();

	Piece* makeMove(Movement& move, bool& isValid);
	void remakeMove(Movement& move, Piece* piece);

	Movement minMax();
	int minMax(Movement& node, int depth, bool maximizingPlayer);
};

