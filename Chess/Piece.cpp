#include "Piece.h"


Piece::Piece(PieceType type, Color color)
{
	this->type = type;

	switch (type){
	case King: 
		this->value = 20;
		break;
	case Queen: 
		this->value = 8.8;
		break;
	case Rook: 
		this->value = 5.1;
		break;
	case Bishop: 
		this->value = 3.33;
		break;
	case Knight:
		this->value = 3.2;
		break;
	case Pawn:
		this->value = 1;
		break;
	}
}


Piece::~Piece()
{
}

Color Piece::getColor(){
	return color;
}

list<GameStatus> Piece::generateMoves(GameStatus & currentGameStatus, int x, int y)
{
	
	list<GameStatus> possibleMoves;
	/*
	switch (type)
	{
	case King:		
		if (currentGameStatus.controlledByWhite(x, y - 1))
		{

		}
		
		
	
	}
	*/
	return possibleMoves;
	
}
