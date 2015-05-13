#pragma once

#include <vector>
#include <list>
#include <algorithm>

#include "Point.h"

class Movement;
class GameStatus;

using namespace std;

enum Color{
	Black,
	White
};

class Piece
{
protected:

	enum PieceType{
		King,
		Queen,
		Rook,
		Bishop,
		Knight,
		Pawn
	};

	vector<vector<int>> pieceSquareTable;

	Color color;

	Point location;

public:
	Piece(Color color, int x, int y);
	virtual list<Movement> generateMoves(GameStatus& currentStatus) = 0;
	Color getColor();
	void setColor(Color color);
	virtual int getValue() = 0;

	Point& getLocation();
	void setLocation(int x, int y);

	virtual PieceType getPieceType() = 0;
};