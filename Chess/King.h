#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class King :
	public Piece
{
public:
	King(Color color);
	~King();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

