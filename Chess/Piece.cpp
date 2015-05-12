#include "Piece.h"

Piece::Piece(Color color)
{
	this->color = color;
}

Color Piece::getColor()
{
	return this->color;
}

void Piece::setColor(Color color)
{
	this->color = color;
}

double Piece::getValue()
{
	return this->value;
}


King::King(Color color) : Piece(color)
{
}

Queen::Queen(Color color) : Piece(color)
{
}

Rook::Rook(Color color) : Piece(color)
{
}

Bishop::Bishop(Color color) : Piece(color)
{
}

Knight::Knight(Color color) : Piece(color)
{
}

Pawn::Pawn(Color color) : Piece(color)
{
}

list<GameStatus> King::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}

list<GameStatus> Queen::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}

list<GameStatus> Rook::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}

list<GameStatus> Bishop::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}

list<GameStatus> Knight::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}

list<GameStatus> Pawn::generateMoves(GameStatus& currentStatus, int x, int y)
{
	return list<GameStatus>();
}




