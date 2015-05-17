#pragma once

#include "Point.h"
#include <string>

using namespace std;

class Movement
{
private:
	Point startPoint;
	Point endPoint;
public:

	Movement();
	Movement(Point& startPoint, Point& endPoint);
	Movement(string move);
	~Movement();

	Point& getStartPoint();
	void setStartPoint(Point& p);

	Point& getEndPoint();
	void setEndPoint(Point& p);

	string toString();


};

