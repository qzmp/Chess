#pragma once
#include "Piece.h"

class Piece;
enum Color;

class Pawn :
	public Piece
{
public:
	Pawn(Color color);
	~Pawn();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

