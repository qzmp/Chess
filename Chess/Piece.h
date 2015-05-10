#pragma once

#include <vector>
#include <list>
//#include "Board.h"

class GameStatus;

using namespace std;

enum Color{
	Black,
	White
};

enum PieceType{
	King,
	Queen,
	Rook,
	Bishop,
	Knight,
	Pawn
};

class Piece
{
	
private:
	double value;
	int xPos;
	int yPos;
	Color color;
	PieceType type;

public:
	Piece(PieceType type, Color color);
	~Piece();

	list<GameStatus> generateMoves(GameStatus& currentStatus);
	Color getColor();
};