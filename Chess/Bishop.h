#pragma once
#include "Piece.h"

class Piece;
enum Color;

class Bishop :
	public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

