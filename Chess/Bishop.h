#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class Bishop :
	public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

