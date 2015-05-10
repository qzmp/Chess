#include "Square.h"


Square::Square()
{
	this->piece = nullptr;
}


Square::~Square()
{
}

void Square::setPiece(Piece& piece)
{
	this->piece = &piece;
}

void Square::removePiece()
{
	this->piece = nullptr;
}

Piece* Square::getPiece()
{
	return this->piece;
}

bool Square::takenBy(Color color)
{
	if (this->piece != nullptr)
		return this->piece->getColor() == color;
	else return false;
}

bool Square::isControlledByBlack()
{
	return controlledByBlack;
}

bool Square::isControlledByWhite()
{
	return controlledByWhite;
}



