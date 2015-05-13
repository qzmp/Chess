#include "Rook.h"


Rook::Rook(Color color, int x, int y) : Piece(color, x, y)
{
}


Rook::~Rook()
{
}

list<Movement> Rook::generateMoves(GameStatus& currentStatus){
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	//top
	int checkedX = x;
	int checkedY = y - 1;
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