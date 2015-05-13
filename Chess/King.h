#pragma once
#include "Piece.h"
#include "GameStatus.h"

class GameStatus;
class Movement;

class King :
	public Piece
{
private:
	bool isCheckedDiagonally(GameStatus& currentStatus);
	bool isCheckedHorizontally(GameStatus& currentStatus);
	bool isCheckedVertically(GameStatus& currentStatus);
	bool isCheckedByKnight(GameStatus& currentStatus);

public:
	King(Color color, int x, int y);
	~King();

	list<Movement> generateMoves(GameStatus& currentStatus);
	bool isChecked(GameStatus& currentStatus);

	PieceType getPieceType();

	int getValue();
};

