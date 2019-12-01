#include <string>
#include <memory>
#include <iostream>
#include "board.h"
#include "textDisplay.h"
#include "basicboard.h"
#include "decorator.h"
#include "force.h"
#include "heavy.h"
#include "blind.h"
#include "game.h"
using namespace std;

Game::Game(int startLevel, bool textOnly, string script1, string script2, unsigned seed): defaultLevel{startLevel}, textOnly{textOnly}, script1{script1}, script2{script2}, seed{seed}, brd1{new BasicBoard(startLevel, textOnly, script1, seed)}, brd2{new BasicBoard(startLevel, textOnly, script2, seed)} {
	brd1->getNextBlock();
}

void Game::restart() {
	brd1 = make_unique<BasicBoard> {defaultLevel, textOnly, script1, seed};
	brd2 = make_unique<BasicBoard> {defaultLevel, textOnly, script2, seed};
}

void Game::print(ostream &out) {
	string td1 = brd1->print();
	string td2 = brd2->print();
	td.print(out, td1, td2);
}

void Game::processCommand(string command, int repeat, int board) {
	Board *tmp;
	Board *tmp2;
	if (board == 1) {
		tmp = brd1.get();
		tmp2 = brd2.get();
	}
	else if (board == 2) {
		tmp = brd2;
		tmp2 = brd1;
	}

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
		int linesCleared = tmp->dropBlock();
		int score = tmp->getScore();
		if (score > highscore) highscore = score;

		// remove special effects from current board if there are any
		if (tmp->inSpecialEffect()) {
			if (board == 1) {
				Decorator *temp = static_cast <Decorator *>(brd1.get());
				brd1 = make_unique<Board> {temp->removeDecorator()};
			} else if (board == 2) {
				Decorator *temp = static_cast <Decorator *>(brd2.get());
				brd2 = make_unique<Board> {temp->removeDecorator()};
			}
		}

		// activate special effects if lines cleared
		if (linesCleared > 0) {
			cout << "Choose your special action" << endl;
			while (true) {
				string action;
				cin >> action;
				if (action == "blind") {
					if (board == 1) {
						brd2 = make_unique<Blind> {tmp2};
						brd2->setSpecialEffect();
					} else if (board == 2) {
						brd1 = make_unique<Blind> {tmp2};
						brd1->setSpecialEffect();
					}
				}
				else if (action == "heavy") {
					if (board == 1) {
						brd2 = make_unique<Heavy> {tmp2};
						brd2->setSpecialEffect();
					} else if (board == 2) {
						brd1 = make_unique<Heavy> {tmp2};
						brd1->setSpecialEffect();
					}
				} 
				else if (action == "force") {
					char type;
					cin >> type;
					if (board == 1) {
						brd2 = make_unique<Force> {tmp2, type};
						brd2->setSpecialEffect();
					} else if (board == 2) {
						brd1 = make_unique<Force> {tmp2, type};
						brd1->setSpecialEffect();
					}
				} 
				else cout << "Invalid input, try again" << endl;
			}
		}
		if (board == 1) brd2->getNextBlock();
		else brd1->getNextBlock();
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
		tmp = brd1;
	else if (board == 2)
		tmp = brd2;

	if (command == "norandom")
		tmp->changeLevel(0, false, filename);
}
