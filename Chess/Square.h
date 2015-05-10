#pragma once

#include "Piece.h"
class Piece;
enum Color;

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
	void removePiece();
	Piece* getPiece();
	bool takenBy(Color color);

	bool isControlledByWhite();
	bool isControlledByBlack();
};

