#pragma once

#include "Point.h"

class Movement
{
private:
	Point startPoint;
	Point endPoint;
public:

	Movement(Point& startPoint, Point& endPoint);
	~Movement();

	Point& getStartPoint();
	void setStartPoint(Point& p);

	Point& getEndPoint();
	void setEndPoint(Point& p);

};

