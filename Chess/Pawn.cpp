#include "Pawn.h"


Pawn::Pawn(Color color, int x, int y) : Piece(color, x, y)
{
	pieceSquareTable =
	{ { 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 50, 50, 50, 50, 50, 50, 50, 50 },
	{ 10, 10, 20, 30, 30, 20, 10, 10 },
	{ 5, 5, 10, 25, 25, 10, 5, 5 },
	{ 0, 0, 0, 20, 20, 0, 0, 0 },
	{ 5, -5, -10, 0, 0, -10, -5, 5 },
	{ 5, 10, 10, -20, -20, 10, 10, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } };

	if (color == Black){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
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

int Pawn::getValue()
{
	return 100 + pieceSquareTable[location.getY()][location.getY()];
}