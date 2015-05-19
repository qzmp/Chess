#include "Rook.h"


Rook::Rook(Color color, int x, int y) : Piece(color, x, y)
{
	pieceSquareTable =
	{ { 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 5, 10, 10, 10, 10, 10, 10, 5 },
	{ -5, 0, 0, 0, 0, 0, 0, -5 },
	{ -5, 0, 0, 0, 0, 0, 0, -5 },
	{ -5, 0, 0, 0, 0, 0, 0, -5 },
	{ -5, 0, 0, 0, 0, 0, 0, -5 },
	{ -5, 0, 0, 0, 0, 0, 0, -5 },
	{ 0, 0, 0, 5, 5, 0, 0, 0 } };

	if (color == White){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
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
	bool captured = false;
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

Piece::PieceType Rook::getPieceType()
{
	return PieceType::Rook;
}

int Rook::getValue()
{
	return 500 + pieceSquareTable[location.getY()][location.getY()];
}