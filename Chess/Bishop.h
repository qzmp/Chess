#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Bishop :
	public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	list<Movement> generateMoves(GameStatus& currentStatus, int x, int y);
};

