#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


Point::~Point()
{
}

int Point::getX()
{
	return x;
}

void Point::setX(int x)
{
	this->x = x;
}

int Point::getY()
{
	return y;
}

void Point::setY(int y)
{
	this->y = y;
}

bool Point::operator==(Point& p1)
{
	return (this->getX() == p1.getX() && this->getY() == p1.getY());
}