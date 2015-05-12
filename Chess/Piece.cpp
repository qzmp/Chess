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
	this->value = 20;
}

Queen::Queen(Color color) : Piece(color)
{
	this->value = 8.8;
}

Rook::Rook(Color color) : Piece(color)
{
	this->value = 5.1;
}

Bishop::Bishop(Color color) : Piece(color)
{
	this->value = 3.33;
}

Knight::Knight(Color color) : Piece(color)
{
	this->value = 3.2;
}

Pawn::Pawn(Color color) : Piece(color)
{
	this->value = 1;
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




