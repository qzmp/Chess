#include "Movement.h"
Movement::Movement(){
	capturing = false;
}

Movement::Movement(Point& startPoint, Point& endPoint)
{
	capturing = false;

	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

Movement::Movement(string move)
{
	int startX = (move[0] - 'a');
	int startY = (move[1] - 48) - 1;
	int endX = (move[2] - 'a');
	int endY = (move[3] - 48) - 1;

	this->startPoint = Point(startX, startY);
	this->endPoint = Point(endX, endY);
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

string Movement::toString()
{
	string result = "";
	char startX = startPoint.getX() + 'a';
	char startY = startPoint.getY() + 48 + 1;
	char endX = endPoint.getX() + 'a';
	char endY = endPoint.getY() + 48 + 1;

	result += startX;
	result += startY;
	result += endX;
	result += endY;

	return result;
}

void Movement::setCapturing()
{
	capturing = true;
}

bool Movement::isCapturing()
{
	return capturing;
}

bool Movement::operator==(Movement& other)
{
	return (this->startPoint == other.getStartPoint()) && (this->endPoint == other.getEndPoint());
}

bool Movement::operator!=(Movement& other)
{
	return (this->startPoint != other.getStartPoint()) || (this->endPoint != other.getEndPoint());
}