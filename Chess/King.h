#pragma once
#include "Piece.h"

class Piece;
enum Color;

class King :
	public Piece
{
public:
	King(Color color);
	~King();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

