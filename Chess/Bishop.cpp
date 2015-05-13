#include "Bishop.h"


Bishop::Bishop(Color color, int x, int y) : Piece(color, x, y)
{
	pieceSquareTable =
	{ { -20, -10, -10, -10, -10, -10, -10, -20 },
	{ -10, 0, 0, 0, 0, 0, 0, -10 },
	{ -10, 0, 5, 10, 10, 5, 0, -10 },
	{ -10, 5, 5, 10, 10, 5, 5, -10 },
	{ -10, 0, 10, 10, 10, 10, 0, -10 },
	{ -10, 10, 10, 10, 10, 10, 10, -10 },
	{ -10, 5, 0, 0, 0, 0, 5, -10 },
	{ -20, -10, -10, -10, -10, -10, -10, -20 } };

	if (color == Black){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
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

	return moves;
}

Piece::PieceType Bishop::getPieceType()
{
	return PieceType::Bishop;
}

int Bishop::getValue(){
	return 330 + pieceSquareTable[location.getY()][location.getY()];
}