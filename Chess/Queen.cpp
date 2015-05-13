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
	bool captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX - 1;
		checkedY = checkedY - 1;
	}

	//top right
	checkedX = x + 1;
	checkedY = y - 1;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX + 1;
		checkedY = checkedY - 1;
	}

	//bottom right
	checkedX = x + 1;
	checkedY = y + 1;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX + 1;
		checkedY = checkedY + 1;
	}

	//bottom left
	checkedX = x - 1;
	checkedY = y + 1;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX - 1;
		checkedY = checkedY + 1;
	}

	//top
	checkedX = x;
	checkedY = y - 1;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedY = checkedY - 1;
	}

	//right
	checkedX = x + 1;
	checkedY = y;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX + 1;
	}

	//bottom
	checkedX = x;
	checkedY = y + 1;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedY = checkedY + 1;
	}

	//left
	checkedX = x - 1;
	checkedY = y;
	captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			captured = true;
		}
		checkedX = checkedX - 1;
	}

	return moves;
}

Piece::PieceType Queen::getPieceType()
{
	return PieceType::Queen;
}