#include "Queen.h"


Queen::Queen(Color color) : Piece(color)
{
}


Queen::~Queen()
{
}

list<Movement> Queen::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<Movement>();
}