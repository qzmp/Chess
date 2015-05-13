#include "Bishop.h"


Bishop::Bishop(Color color, int x, int y) : Piece(color, x, y)
{
}


Bishop::~Bishop()
{
}

list<Movement> Bishop::generateMoves(GameStatus& currentStatus){

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

	return moves;
}