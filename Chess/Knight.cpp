#include "Knight.h"


Knight::Knight(Color color, int x, int y) : Piece(color, x, y)
{
	pieceSquareTable =
	{ { -50, -40, -30, -30, -30, -30, -40, -50 },
	{ -40, -20, 0, 0, 0, 0, -20, -40 },
	{ -30, 0, 10, 15, 15, 10, 0, -30 },
	{ -30, 5, 15, 20, 20, 15, 5, -30 },
	{ -30, 0, 15, 20, 20, 15, 0, -30 },
	{ -30, 5, 10, 15, 15, 10, 5, -30 },
	{ -40, -20, 0, 5, 5, 0, -20, -40 },
	{ -50, -40, -30, -30, -30, -30, -40, -50 } };

	if (color == White){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
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

int Knight::getValue()
{
	return 320 + pieceSquareTable[location.getY()][location.getY()];
}
