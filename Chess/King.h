#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class King :
	public Piece
{


public:
	King(Color color, int x, int y);
	~King();

	list<Movement> generateMoves(GameStatus& currentStatus);

	PieceType getPieceType();

	int getValue();
};

