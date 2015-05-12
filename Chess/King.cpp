#include "King.h"


King::King(Color color) : Piece(color)
{
}


King::~King()
{
}

list<GameStatus> King::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<GameStatus>();
}
