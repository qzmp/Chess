#include "Queen.h"


Queen::Queen(Color color, int x, int y) : Piece(color, x, y)
{
}


Queen::~Queen()
{
}

list<Movement> Queen::generateMoves(GameStatus& currentStatus){
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	//top left
	int checkedX = x - 1;
	int checkedY = y - 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX - 1;
		checkedY = checkedY - 1;
	}

	//top right
	checkedX = x + 1;
	checkedY = y - 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX + 1;
		checkedY = checkedY - 1;
	}

	//bottom right
	checkedX = x + 1;
	checkedY = y + 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX + 1;
		checkedY = checkedY + 1;
	}

	//bottom left
	checkedX = x - 1;
	checkedY = y + 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX - 1;
		checkedY = checkedY + 1;
	}

	//top
	checkedX = x;
	checkedY = y - 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedY = checkedY - 1;
	}

	//right
	checkedX = x + 1;
	checkedY = y;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX + 1;
	}

	//bottom
	checkedX = x;
	checkedY = y + 1;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedY = checkedY + 1;
	}

	//left
	checkedX = x - 1;
	checkedY = y;
	while (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		checkedX = checkedX - 1;
	}

	return moves;
}