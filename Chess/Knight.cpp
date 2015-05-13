#include "Knight.h"


Knight::Knight(Color color, int x, int y) : Piece(color, x, y)
{
}


Knight::~Knight()
{
}

list<Movement> Knight::generateMoves(GameStatus& currentStatus){
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	//top top left
	int checkedX = x - 1;
	int checkedY = y - 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom top left
	checkedX = x - 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top top right
	checkedX = x + 1;
	checkedY = y - 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom top right
	checkedX = x + 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top bottom right
	checkedX = x + 2;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom bottom right
	checkedX = x + 1;
	checkedY = y + 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top bottom left
	checkedX = x - 1;
	checkedY = y + 2;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom bottom left
	checkedX = x - 2;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	return moves;
}

Piece::PieceType Knight::getPieceType()
{
	return PieceType::Knight;
}