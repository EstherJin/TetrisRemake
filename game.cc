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

Game::Game(int startLevel, bool textOnly, string script1, string script2, unsigned seed): defaultLevel{startLevel}, textOnly{textOnly}, script1{script1}, script2{script2}, seed{seed} {
	brd1 = make_shared <BasicBoard> (1, startLevel, startLevel, textOnly, script1, seed);
	brd2 = make_shared <BasicBoard> (2, startLevel, startLevel, textOnly, script2, seed);
	if (startLevel >= 3) {
		brd1 = make_shared<Heavy> (brd1);
		brd2 = make_shared<Heavy> (brd2);
	}
	brd1->getNextBlock();
}

void Game::restart() {
	brd1 = make_shared<BasicBoard> (1, defaultLevel, defaultLevel, textOnly, script1, seed);
	brd2 = make_shared<BasicBoard> (2, defaultLevel, defaultLevel, textOnly, script2, seed);
}

void Game::print(ostream &out) {
	string td1 = brd1->print();
	string td2 = brd2->print();
	td.print(out, td1, td2);
}

void Game::processWinner() {
	// calculate scores
	if (brd1->getScore() > brd2->getScore()) {
		cout << "Winner is Player 1!!! :)" << endl;
	} else if (brd2->getScore() > brd1->getScore()) {
		cout << "Winner is Player 2!!! :)" << endl;
	} else {
		cout << "Tie! Good game everyone :)" << endl;
	}
	throw "end game";
}

void Game::processDropCmd(int linesCleared, int board) {
	Board *tmp;
	Board *tmp2;
	if (board == 1) {
		tmp = brd1.get();
		tmp2 = brd2.get();
	}
	else if (board == 2) {
		tmp = brd2.get();
		tmp2 = brd1.get();
	}

	int score = tmp->getScore();
	if (score > highscore) highscore = score;

	// remove special effects from current board if there are any
	if (tmp->inSpecialEffect()) {
		if (board == 1) {
			Decorator *temp = static_cast <Decorator *>(brd1.get());
			brd1 = temp->removeDecorator();
		} else if (board == 2) {
			Decorator *temp = static_cast <Decorator *>(brd2.get());
			brd2 = temp->removeDecorator();
		}
	}

	// activate special effects if lines cleared
	if (linesCleared > 1) {
		cout << "Choose your special action" << endl;
		while (true) {
			string action;
			cin >> action;
			if (action == "blind") {
				if (board == 1) {
					brd2 = make_shared<Blind> (brd2);
					brd2->setSpecialEffect();
				} else if (board == 2) {
					brd1 = make_shared<Blind> (brd1);
					brd1->setSpecialEffect();
				}
				break;
			}
			else if (action == "heavy") {
				if (board == 1) {
					brd2 = make_shared<Heavy> (brd2);
					brd2->setSpecialEffect();
				} else if (board == 2) {
					brd1 = make_shared<Heavy> (brd1);
					brd1->setSpecialEffect();
				}
				break;
			}
			else if (action == "force") {
				char type;
				cin >> type;
				if (board == 1) {
					brd2 = make_shared<Force> (brd2, type);
					brd2->setSpecialEffect();
				} else if (board == 2) {
					brd1 = make_shared<Force> (brd1, type);
					brd1->setSpecialEffect();
				}
				break;
			}
			else cout << "Invalid input, try again" << endl;
		}
	}
	if (board == 1) brd2->getNextBlock();
	else brd1->getNextBlock();

	// check game over
	if (!brd1->validStartPos() || !brd2->validStartPos()) processWinner();

	throw 1;
}

void Game::processCommand(string command, int repeat, int board) {
	Board *tmp;
	Board *tmp2;
	if (board == 1) {
		tmp = brd1.get();
		tmp2 = brd2.get();
	}
	else if (board == 2) {
		tmp = brd2.get();
		tmp2 = brd1.get();
	}
	if (command == "left") {
		try {
			tmp->moveBlock(repeat * -1);
		}
		catch (char *gameOver) {
			processWinner();
		}
		catch (int linesCleared) {
			processDropCmd(linesCleared, board);
		}
	}
	else if (command == "right") {
		try {
			tmp->moveBlock(repeat);
		}
		catch (char *gameOver) {
			processWinner();
		}
		catch (int linesCleared) {
			processDropCmd(linesCleared, board);
		}
	}
	else if (command == "down")
		try {
			tmp->downBlock(repeat);
		}
		catch (char *gameOver) {
			processWinner();
		}
		catch (int linesCleared) {
			processDropCmd(linesCleared, board);
		}
	else if (command == "clockwise")
		tmp->turnBlock(repeat);
	else if (command == "counterclockwise")
		tmp->turnBlock(repeat * -1);
	else if (command == "drop") {
		try {
			tmp->dropBlock();
		}
		catch (int linesCleared) {
			processDropCmd(linesCleared, board);
		}
	}
	else if (command == "levelup") {
		tmp->changeLevel(repeat, false, "");
		if (tmp->getLevel() >= 3) {
			if (board == 1) brd1 = make_shared<Heavy> (brd1);
			else if (board == 2) brd2 = make_shared<Heavy> (brd2);
		}
	}
	else if (command == "leveldown") {
		tmp->changeLevel(repeat * -1, false, "");
		if (tmp->getLevel() >= 3) {
			if (board == 1) brd1 = make_shared<Heavy> (brd1);
			else if (board == 2) brd2 = make_shared<Heavy> (brd2);
		}
	}
	else if (command == "random")
		tmp->changeLevel(0, true, "");
	else if (command == "restart")
		restart();
}


void Game::processCommand(string command, string filename, int repeat, int board) {
	Board *tmp;
	if (board == 1)
		tmp = brd1.get();
	else if (board == 2)
		tmp = brd2.get();

	if (command == "norandom")
		tmp->changeLevel(0, false, filename);
}
