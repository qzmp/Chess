#include "Piece.h"

Piece::Piece(Color color, int x, int y)
{
	this->color = color;
	this->location = Point(x, y);
}

Color Piece::getColor()
{
	return this->color;
}

void Piece::setColor(Color color)
{
	this->color = color;
}

Point& Piece::getLocation()
{
	return this->location;
}

void Piece::setLocation(int x, int y)
{
	this->location = Point(x, y);
}

