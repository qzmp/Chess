#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class King :
	public Piece
{
public:
	King(Color color);
	~King();

	list<Movement> generateMoves(GameStatus& currentStatus, int x, int y);
};

