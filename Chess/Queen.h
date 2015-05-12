#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Queen :
	public Piece
{
public:
	Queen(Color color);
	~Queen();

	list<Movement> generateMoves(GameStatus& currentStatus, int x, int y);
};

