#include "Bishop.h"


Bishop::Bishop(Color color) : Piece(color)
{
}


Bishop::~Bishop()
{
}

list<GameStatus> Bishop::generateMoves(GameStatus& currentStatus, int x, int y){
	return list<GameStatus>();
}