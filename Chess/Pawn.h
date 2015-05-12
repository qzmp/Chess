#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Pawn :
	public Piece
{
public:
	Pawn(Color color);
	~Pawn();

	list<Movement> generateMoves(GameStatus& currentStatus, int x, int y);
};

