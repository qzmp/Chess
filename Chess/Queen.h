#pragma once
#include "Piece.h"

class Piece;
enum Color;

class Queen :
	public Piece
{
public:
	Queen(Color color);
	~Queen();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

