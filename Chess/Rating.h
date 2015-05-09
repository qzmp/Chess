#pragma once

#include "Board.h"

class Rating
{
public:
	Rating();
	~Rating();

	static double Rate(Board board);
};

