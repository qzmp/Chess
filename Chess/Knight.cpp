#include "Knight.h"


Knight::Knight(Color color) : Piece(color)
{
}


Knight::~Knight()
{
}

list<Movement> Knight::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<Movement>();
}