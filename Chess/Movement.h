#pragma once

#include "GameStatus.h"

class Movement
{
public:

	static void moveUp(vector<vector<Square>> & board, int x, int y);
	static void moveDown(vector<vector<Square>> & board, int x, int y);
	static void moveRight(vector<vector<Square>> & board, int x, int y);
	static void moveLeft(vector<vector<Square>> & board, int x, int y);

	static void moveUpLeft(vector<vector<Square>> & board, int x, int y);
	static void moveUpRight(vector<vector<Square>> & board, int x, int y);
	static void moveDownLeft(vector<vector<Square>> & board, int x, int y);
	static void moveDownRight(vector<vector<Square>> & board, int x, int y);



};

