#include "King.h"


King::King(Color color) : Piece(color)
{
}


King::~King()
{
}

list<Movement> King::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<Movement>();
}
