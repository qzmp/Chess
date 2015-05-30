#pragma once

#include <limits>
#include <iostream>
#include <fstream>

#include "Movement.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Piece;

class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;
enum Color;


using namespace std;

class GameStatus
{
	
private:
	const int DEPTH = 4;
	vector<vector<Piece*>> board;
	list<Piece*> pieces;

	Color currentPlayer;

	bool isAttackedDiagonally(Piece& piece);
	bool isAttackedHorizontally(Piece& piece);
	bool isAttackedVertically(Piece& piece);
	bool isAttackedByKnight(Piece& piece);

	Color getMinMaxPlayer(bool maximizing);

	int visitNum = 0;

public:
	enum Mode{
		STANDARD,
		NOAB,
		CAPTURE,
	};

	GameStatus();
	~GameStatus();
	
	void startSetup();
	void testSetup();
	
	bool isChecked(Piece& piece);
	
	vector<vector<Piece*>>& getBoard();
	Piece& getPiece(Point& location);

	list<Movement> generateMoves(Color player);

	Movement Move();

	Color getCurrentPlayer();

	bool isAvailable(int x, int y);
	bool isOccupied(int x, int y);
	bool isOccupied(Point location);
	bool isColor(int x, int y, Color color);
	bool canPlace(int x, int y, Color color);

	int rate();

	Piece* makeMove(Movement& move, bool& isValid);
	void makeValidMove(Movement& move);
	void remakeMove(Movement& move, Piece* piece);

	Movement& minMax(Movement moveBeforeLast, Mode mode);
	int minMax(int depth, int a, int b, bool maximizingPlayer);
	int minMax(int depth, bool maximizingPlayer);
	int minMaxCapture(int depth, int a, int b, bool maximizingPlayer);

	void changePlayer();

	Piece* WhiteKing;
	Piece* BlackKing;

	void upgradePawn(int x, int y);

	void testAlfaBeta();
};

