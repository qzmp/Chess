#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Knight :
	public Piece
{
public:
	Knight(Color color, int x, int y);
	~Knight();

	list<Movement> generateMoves(GameStatus& currentStatus);

	PieceType getPieceType();

	int getValue();
};

