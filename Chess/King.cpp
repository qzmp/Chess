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

	if (color == White){
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
	moves.splice(moves.end(), generateMoves(currentStatus, -1, -1));

	//top
	moves.splice(moves.end(), generateMoves(currentStatus, 0, -1));

	//top right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, -1));

	//right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, 0));

	//bottom right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, 1));

	//bottom
	moves.splice(moves.end(), generateMoves(currentStatus, 0, 1));

	//bottom left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, 1));

	//left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, 0));

	return moves;
}

list<Movement> King::generateMoves(GameStatus& currentStatus, int dirX, int dirY)
{
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	int checkedX = x + dirX;
	int checkedY = y + dirY;

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