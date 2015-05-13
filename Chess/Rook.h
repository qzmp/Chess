#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Rook :
	public Piece
{
public:
	Rook(Color color, int x, int y);
	~Rook();

	list<Movement> generateMoves(GameStatus& currentStatus);
};
