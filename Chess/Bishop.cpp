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

	if (color == White){
		reverse(pieceSquareTable.begin(), pieceSquareTable.end());
	}
}


Bishop::~Bishop()
{
}

list<Movement> Bishop::generateMoves(GameStatus& currentStatus){

	list<Movement> moves;

	//top left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, -1));

	//top right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, -1));

	//bottom right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, 1));

	//bottom left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, 1));

	return moves;
}

list<Movement> Bishop::generateMoves(GameStatus& currentStatus, int dirX, int dirY)
{
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	int checkedX = x + dirX;
	int checkedY = y + dirY;
	bool captured = false;
	while (currentStatus.canPlace(checkedX, checkedY, this->color) && !captured)
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			moves.back().setCapturing();
			captured = true;
		}
		checkedX = checkedX + dirX;
		checkedY = checkedY + dirY;
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