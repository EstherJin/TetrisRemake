#ifndef GAME_H
#define GAME_H
#include <string>
#include <memory>
#include <iostream>
#include "board.h"
#include "textDisplay.h"

class Game {
	const int rows = 18;
	int highscore = 0;
	int defaultLevel;
	bool textOnly;
	std::string script1, script2;
	unsigned seed;
	std::unique_ptr<Board> brd1;
	std::unique_ptr<Board> brd2;
	TextDisplay td;
public:
	Game(int startLevel = 0, bool textOnly = false, std::string script1 = "sequence1.txt", std::string script2 = "sequence2.txt", unsigned seed = 0);
	void restart();
	void print(std::ostream &out);
	void processCommand(std::string command, int repeat, int board);
	void processCommand(std::string command, std::string filename, int repeat, int board);
};

#endif