#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class Rook :
	public Piece
{
public:
	Rook(Color color);
	~Rook();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};
