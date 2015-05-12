#pragma once
#include "Piece.h"

class Piece;
enum Color;

class Rook :
	public Piece
{
public:
	Rook(Color color);
	~Rook();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};
