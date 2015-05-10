#pragma once

#include <vector>
#include <list>
#include "GameStatus.h"

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
	Color color;
	PieceType type;

public:
	Piece(PieceType type, Color color);
	~Piece();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
	Color getColor();
};