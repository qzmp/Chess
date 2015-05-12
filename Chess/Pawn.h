#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;

class Pawn :
	public Piece
{
public:
	Pawn(Color color);
	~Pawn();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

