#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Queen :
	public Piece
{
public:
	Queen(Color color, int x, int y);
	~Queen();

	list<Movement> generateMoves(GameStatus& currentStatus);
	list<Movement> generateMoves(GameStatus& currentStatus, int dirX, int dirY);

	PieceType getPieceType();

	int getValue();
};

