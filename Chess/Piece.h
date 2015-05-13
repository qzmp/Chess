#pragma once

#include <vector>
#include <list>
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

	double value;
	Color color;

	Point location;

public:
	Piece(Color color, int x, int y);
	virtual list<Movement> generateMoves(GameStatus& currentStatus) = 0;
	Color getColor();
	void setColor(Color color);
	double getValue();

	Point& getLocation();
	void setLocation(int x, int y);

	virtual PieceType getPieceType() = 0;
};