#include "Pawn.h"


Pawn::Pawn(Color color, int x, int y) : Piece(color, x, y)
{
	this->value = 1;
}


Pawn::~Pawn()
{
}

list<Movement> Pawn::generateMoves(GameStatus& currentStatus){
	
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	int checkedX;
	int checkedY;

	//White
	if (this->color == White)
	{
		//standard move
		checkedX = x;
		checkedY = y - 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && !currentStatus.isOccupied(checkedX, checkedY))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}

		//double move
		if (location.getY() == 6)
		{
			checkedX = x;
			checkedY = y - 2;
			if (!currentStatus.isOccupied(checkedX, checkedY))
			{
				moves.push_back(Movement(location, Point(checkedX, checkedY)));
			}
		}

		//capture left
		checkedX = x - 1;
		checkedY = y - 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && currentStatus.isOccupied(checkedX, checkedY) && !currentStatus.isColor(checkedX, checkedY, this->color))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}

		//capture right
		checkedX = x + 1;
		checkedY = y - 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && currentStatus.isOccupied(checkedX, checkedY) && !currentStatus.isColor(checkedX, checkedY, this->color))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}
	}
	else //Black
	{
		//standard move
		checkedX = x;
		checkedY = y + 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && !currentStatus.isOccupied(checkedX, checkedY))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}

		//double move
		if (location.getY() == 1)
		{
			checkedX = x;
			checkedY = y + 2;
			if (!currentStatus.isOccupied(checkedX, checkedY))
			{
				moves.push_back(Movement(location, Point(checkedX, checkedY)));
			}
		}

		//capture left
		checkedX = x - 1;
		checkedY = y + 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && currentStatus.isOccupied(checkedX, checkedY) && !currentStatus.isColor(checkedX, checkedY, this->color))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}

		//capture right
		checkedX = x + 1;
		checkedY = y + 1;
		if (currentStatus.isAvailable(checkedX, checkedY) && currentStatus.isOccupied(checkedX, checkedY) && !currentStatus.isColor(checkedX, checkedY, this->color))
		{
			moves.push_back(Movement(location, Point(checkedX, checkedY)));
		}
	}
	
	return moves;
}

Piece::PieceType Pawn::getPieceType()
{
	return PieceType::Pawn;
}