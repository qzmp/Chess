#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Knight :
	public Piece
{
public:
	Knight(Color color);
	~Knight();

	list<Movement> generateMoves(GameStatus& currentStatus, int x, int y);
};

