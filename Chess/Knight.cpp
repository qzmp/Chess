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

	//top top left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, -2));

	//bottom top left
	moves.splice(moves.end(), generateMoves(currentStatus, -2, -1));

	//top top right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, -2));

	//bottom top right
	moves.splice(moves.end(), generateMoves(currentStatus, 2, -1));

	//top bottom right
	moves.splice(moves.end(), generateMoves(currentStatus, 2, -1));

	//bottom bottom right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, 2));

	//top bottom left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, 2));

	//bottom bottom left
	moves.splice(moves.end(), generateMoves(currentStatus, -2, 1));

	return moves;
}

list<Movement> Knight::generateMoves(GameStatus& currentStatus, int dirX, int dirY)
{
	list<Movement> moves;

	int x = location.getX();
	int y = location.getY();

	int checkedX = x + dirX;
	int checkedY = y + dirY;
	if (currentStatus.canPlace(checkedX, checkedY, this->color))
	{
		moves.push_back(Movement(location, Point(checkedX, checkedY)));
		if (currentStatus.isOccupied(checkedX, checkedY))
		{
			moves.back().setCapturing();
		}
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
