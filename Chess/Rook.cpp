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

	//top
	moves.splice(moves.end(), generateMoves(currentStatus, 0, -1));

	//right
	moves.splice(moves.end(), generateMoves(currentStatus, 1, 0));

	//bottom
	moves.splice(moves.end(), generateMoves(currentStatus, 0, 1));

	//left
	moves.splice(moves.end(), generateMoves(currentStatus, -1, 0));

	return moves;
}

list<Movement> Rook::generateMoves(GameStatus& currentStatus, int dirX, int dirY){
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

Piece::PieceType Rook::getPieceType()
{
	return PieceType::Rook;
}

int Rook::getValue()
{
	return 500 +pieceSquareTable[location.getY()][location.getY()];
}