#pragma once

#include <vector>
#include <list>

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
	double value;
	Color color;

public:
	Piece(Color color);
	virtual list<Movement> generateMoves(GameStatus& currentStatus, int x, int y) = 0;
	Color getColor();
	void setColor(Color color);
	double getValue();
};