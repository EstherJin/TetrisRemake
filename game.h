#ifndef GAME_H
#define GAME_H
#include <string>
#include <memory>
#include <iostream>

class Board;
class TextDisplay;
class Game {
	const rows = 18;
	int highscore = 0;
	std::unique_ptr<Board> brd1 {new Board()};
	std::unique_ptr<Board> brd2 {new Board()};
	std::unique_ptr<TextDisplay> td {new TextDisplay()};
public:
	Game(int startLevel = 0, bool textOnly = false, std::string script1 = "sequence1.txt", std::string script2 = "sequence2.txt", unsigned seed = 0);
	void restart();
	void print(std::ostream &out);
	void processCommand(std::string command, int repeat, int board);
	void processCommand(std::string command, std::string filename, int repeat, int board);
};

#endif