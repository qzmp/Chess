#pragma once

#include "Point.h"
#include <string>

using namespace std;

class Movement
{
private:
	Point startPoint;
	Point endPoint;

	bool capturing;

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

	void setCapturing();
	bool isCapturing();

	bool operator==(Movement& other);
	bool operator!=(Movement& other);

};

