#include "Rook.h"


Rook::Rook(Color color) : Piece(color)
{
}


Rook::~Rook()
{
}

list<Movement> Rook::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<Movement>();
}