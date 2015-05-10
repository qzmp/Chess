#pragma once

#include "Piece.h"
class Square
{
private:
	Piece* piece;
	bool controlledByBlack;
	bool controlledByWhite;

public:
	Square();
	~Square();

	void setPiece(Piece& piece);
	Piece* getPiece();
	bool takenBy(Color color);
};

