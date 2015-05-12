#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class Queen :
	public Piece
{
public:
	Queen(Color color);
	~Queen();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

