#include <iostream>
#include <string>
//#include <queue>
#include "GameStatus.h"

using namespace std;

int main()
{
	bool isValid = true;
	GameStatus board = GameStatus();
	/*
	board.testSetup();
	board.isChecked(*board.WhiteKing);
	Movement test = Movement("f4e5");
	board.makeMove(test, isValid);
	cout << "test";
	*/
	
	Movement bestMove;

	Movement moveBeforeLast;
	
	string Line; //to read the command given by the GUI
	string move;
	int flag = 1; //to change the value of chess squares from 'a' to 'h'

	cout.setf(ios::unitbuf);// Make sure that the outputs are sent straight away to the GUI

	cout << "uci";

	while (getline(cin, Line)) {
		string test = Line.substr(0, 23);
		if (Line == "uci") {
			cout << "id name Deep Yellow" << endl;
			cout << "id author sqmp" << endl;
			cout << "uciok" << endl;
		}
		else if (Line == "quit") {
			cout << "Bye Bye" << endl;
			break;
		}
		else if (Line == "isready") {
			cout << "readyok" << endl;
		}
		else if (Line == "ucinewgame") {
			board.startSetup();
		}
		else if (Line.substr(0, 23) == "position startpos moves") {
			board.startSetup();
			int pos = 24;
			while ((pos + 4) <= Line.length())
			{
				string move = Line.substr(pos, 4);
				bestMove = Movement(move);
				board.makeValidMove(bestMove);
				board.changePlayer();
				pos += 5;
			}

			if (pos - 20 > 23)
			{
				moveBeforeLast = Line.substr(pos - 20, 4);
			}			
		}
		else if (Line == "stop") {
			; // nothing to do
		}
		else if (Line.substr(0, 2) == "go") {
			// Received a command like: "go infinite"
			bestMove = board.minMax(moveBeforeLast);
			move = bestMove.toString();
			if (move != "a1a1")
			{
				board.makeMove(bestMove, isValid);
				cout << "bestmove " << move << endl;
			}
			
			//Output like: "bestmove h7h5"
		}
	}
	
	return 0;
}
