#include <iostream>
#include <string>
#include "GameStatus.h"

using namespace std;

int main()
{
	bool isValid = true;
	GameStatus board = GameStatus();
	
	board.startSetup();
	board.generateMoves();
	Movement test = Movement("d2d4");
	cout << test.toString();
	board.makeMove(test, isValid);
	cout << "test";
	
	
	Movement bestMove;
	
	string Line; //to read the command given by the GUI
	string move;
	int flag = 1; //to change the value of chess squares from 'a' to 'h'

	cout.setf(ios::unitbuf);// Make sure that the outputs are sent straight away to the GUI

	cout << "uci";

	while (getline(cin, Line)) {
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

		if (Line.substr(0, 23) == "position startpos moves ") {
			string move = Line.substr(Line.length() - 5, Line.length() - 1);
			bestMove = Movement(move);
			board.makeMove(bestMove, isValid);
		}
		else if (Line == "stop") {
			; // nothing to do
		}
		else if (Line.substr(0, 3) == "go ") {
			// Received a command like: "go wtime 300000 btime 300000 winc 0 binc 0"
			bestMove = board.minMax();
			move = bestMove.toString();
			board.makeMove(bestMove, isValid);
			cout << "bestmove " << move << endl;
			//Output like: "bestmove h7h5"
		}
	}
	
	return 0;
}
