#pragma once

#include <vector>
#include <list>
#include "GameStatus.h"

class GameStatus;

using namespace std;

enum Color{
	Black,
	White
};

class Piece
{
protected:
	double value;
	Color color;

public:
	Piece(Color color);
	virtual list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y) = 0;
	Color getColor();
	void setColor(Color color);
	double getValue();
};

class Bishop :
	public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

class King :
	public Piece
{
public:
	King(Color color);
	~King();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

class Knight :
	public Piece
{
public:
	Knight(Color color);
	~Knight();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};

class Pawn :
	public Piece
{
public:
	Pawn(Color color);
	~Pawn();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};


class Queen :
	public Piece
{
public:
	Queen(Color color);
	~Queen();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};


class Rook :
	public Piece
{
public:
	Rook(Color color);
	~Rook();

	list<GameStatus> generateMoves(GameStatus& currentStatus, int x, int y);
};
