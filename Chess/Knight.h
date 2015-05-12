#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class Knight :
	public Piece
{
public:
	Knight(Color color);
	~Knight();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

