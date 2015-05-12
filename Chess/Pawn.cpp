#include "Pawn.h"


Pawn::Pawn(Color color) : Piece(color)
{
	this->value = 1;
}


Pawn::~Pawn()
{
}

list<GameStatus> Pawn::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<GameStatus>();
}