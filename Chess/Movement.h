#pragma once

#include "GameStatus.h"

class Movement
{
public:

	static void moveUp(vector<vector<Piece*>> & board, int x, int y);
	static void moveDown(vector<vector<Piece*>> & board, int x, int y);
	static void moveRight(vector<vector<Piece*>> & board, int x, int y);
	static void moveLeft(vector<vector<Piece*>> & board, int x, int y);

	static void moveUpLeft(vector<vector<Piece*>> & board, int x, int y);
	static void moveUpRight(vector<vector<Piece*>> & board, int x, int y);
	static void moveDownLeft(vector<vector<Piece*>> & board, int x, int y);
	static void moveDownRight(vector<vector<Piece*>> & board, int x, int y);



};

