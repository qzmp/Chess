#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class Bishop :
	public Piece
{
public:
	Bishop(Color color, int x, int y);
	~Bishop();

	list<Movement> generateMoves(GameStatus& currentStatus);

	PieceType getPieceType();
};

