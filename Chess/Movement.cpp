#include "Movement.h"
Movement::Movement(){

}

Movement::Movement(Point& startPoint, Point& endPoint)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

Movement::~Movement()
{

}

Point& Movement::getStartPoint()
{
	return this->startPoint;
}

void Movement::setStartPoint(Point& p)
{
	this->startPoint = startPoint;
}

Point& Movement::getEndPoint()
{
	return this->endPoint;
}

void Movement::setEndPoint(Point& p)
{
	this->endPoint = endPoint;
}
