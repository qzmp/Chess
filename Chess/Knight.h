#pragma once
#include "Piece.h"

class Piece;
enum Color;

class Knight :
	public Piece
{
public:
	Knight(Color color);
	~Knight();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

