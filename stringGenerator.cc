#include "subject.h"
#include "stringGenerator.h"
#include "state.h"
#include <vector>
#include <string>
using namespace std;

StringGenerator::StringGenerator() {
	vector<vector<char>> newGrid;

	for (int i = 0; i < gridRows; ++i) {
		vector<char> row;
		newGrid.emplace_back(row);
		for (int j = 0; j < gridCols; ++j) {
			newGrid[i].emplace_back(' ');
		}
	}

	grid = newGrid;
}

void StringGenerator::notify(Subject &whoNotified) { // update the display for one cell
	State st = whoNotified.getState();
	if (st.add) {
		grid[st.coords.row][st.coords.col] = st.type;
	}
	else {
		grid[st.coords.row][st.coords.col] = ' ';
	}
}

string StringGenerator::print(int level, int score, bool blind, char next) { // generate a string that represents one board
	string str = "";

	str += "Level:    " + to_string(level) + "\n";
	str += "Score:    " + to_string(score) + "\n";

	for (int i = 0; i < gridCols; ++i) {
		str += "-";
	}
	str += "\n";

	// does row and col start from 0?
	for (int i = 0; i < gridRows; ++i) {
		for (int j = 0; j < gridCols; ++j) {
			if (blind) {
				if ((i >= 3 && i <= 12) || (j >= 3 && j <= 9)) {
					str += "?";
				}
			}
			else {
				str += grid.at(i).at(j);
			}
		}
		str += "\n";
	}

	for (int i = 0; i < gridCols; ++i) {
		str += "-";
	}
	str += "\n";

	str += "Next:      \n";

	if (next != ' ') {
		switch (next) {
		case 'I':
			str += "           \nIIII       \n";
			break;
		case 'J':
			str += "J          \nJJJ        \n";
			break;
		case 'L':
			str += "  L        \nLLL        \n";
			break;
		case 'O':
			str += "OO         \nOO         \n";
			break;
		case 'S':
			str += " SS        \nSS         \n";
			break;
		case 'Z':
			str += "ZZ         \n ZZ        \n";
			break;
		case 'T':
			str += "TTT        \n T         \n";
			break;
		}
	}
	else {
		str += "           \n           \n";
	}

	return str;
}
