#include "Piece.h"

Piece::Piece(Color color)
{
	this->color = color;
}

Color Piece::getColor()
{
	return this->color;
}

void Piece::setColor(Color color)
{
	this->color = color;
}

double Piece::getValue()
{
	return this->value;
}

