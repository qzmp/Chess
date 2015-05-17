#include "King.h"


King::King(Color color, int x, int y) : Piece(color, x, y)
{
	
	pieceSquareTable =
	{ { -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -30, -40, -40, -50, -50, -40, -40, -30 },
	{ -20, -30, -30, -40, -40, -30, -30, -20 },
	{ -10, -20, -20, -20, -20, -20, -20, -10 },
	{ 20, 20, 0, 0, 0, 0, 20, 20 },
	{ 20, 30, 10, 0, 0, 10, 30, 20 } };

	if (color == Black){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
	
}


King::~King()
{
}

list<Movement> King::generateMoves(GameStatus& currentStatus){

	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	//top left
	int checkedX = x - 1;
	int checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top
	checkedX = x;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//top right
	checkedX = x + 1;
	checkedY = y - 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//right
	checkedX = x + 1;
	checkedY = y;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom right
	checkedX = x + 1;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom
	checkedX = x;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//bottom left
	checkedX = x - 1;
	checkedY = y + 1;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	//left
	checkedX = x - 1;
	checkedY = y;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
	}

	return moves;
}



Piece::PieceType King::getPieceType()
{
	return PieceType::King;
}

int King::getValue()
{
	return 20000 + pieceSquareTable[location.getY()][location.getY()];
}