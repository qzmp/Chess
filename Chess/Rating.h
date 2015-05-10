#pragma once

#include "GameStatus.h"

class Rating
{
public:
	Rating();
	~Rating();

	static double Rate(GameStatus board);
};

