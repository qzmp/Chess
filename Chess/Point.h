#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int x, int y);
	~Point();

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	bool operator==(Point& p1);
	bool operator!=(Point& p1);
};

