#include <string>
#include <memory>
#include <iostream>
#include "board.h"
#include "game.h"
using namespace std;

Game::Game(int startLevel): brd1{new Board(startLevel)}, brd2{new Board(startLevel)} {
	brd1->getNextBlock();
}

void Game::restart() {
	brd1 = new Board();
	brd2 = new Board();
}

void Game::print(ostream &out) {
	string td1 = board1->print();
	string td2 = board2->print();
	td->print(out, td1, td2);
}

void Game::processCommand(string command, int repeat, int board) {
	Board *tmp;
	if (board == 1) 
		tmp = board1;
	else if (board == 2)
		tmp = board2;

	if (command == "left")
		tmp->moveBlock(repeat * -1);
	else if (command == "right")
		tmp->moveBlock(repeat);
	else if (command == "down")
		tmp->downBlock(repeat);
	else if (command == "clockwise")
		tmp->turnBlock(repeat);
	else if (command == "counterclockwise")
		tmp->turnBlock(repeat * -1);
	else if (command == "drop") {
		tmp->dropBlock();
		int score = tmp->getScore();
		if (score > highscore) highscore = score;
		// TO DO: activate special effects if lines cleared
	}
	else if (command == "levelup")
		tmp->changeLevel(repeat);
	else if (command == "leveldown")
		tmp->changeLevel(repeat * -1);
	else if (command == "random")
		tmp->changeLevel(0, true, "");
	else if (command == "restart")
		restart();
}


void Game::processCommand(string command, string filename, int repeat, int board) {
	Board *tmp;
	if (board == 1) 
		tmp = board1;
	else if (board == 2)
		tmp = board2;

	if (command == "norandom")
		tmp->changeLevel(0, false, filename);
}
