#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"
#include "block1.h"
#include "i.h"
#include "j.h"
#include "s.h"
#include "z.h"
#include "t.h"
#include "o.h"
#include "l.h"
#include "block2.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "NonRandom.h"
#include "stringGenerator.h"
// #include "graphicsDisplay.h"
#include "coordinates.h"
#include "basicboard.h"
using namespace std;

BasicBoard::BasicBoard(int player, bool random, int level, bool textOnly, string script, unsigned seed): player{player}, random{random}, textOnly{textOnly}, seed{seed} {
	for (int r = 0; r < gridRows; ++r) {
		Row row{r, &sg, &gd};
		grid.emplace_back(row);
	}

	if (level == 1) lvl = make_unique<Level1> (seed);
	else if (level == 2) lvl = make_unique<Level2> (seed);
	else if (level == 3) lvl = make_unique<Level3> (seed);
	else if (level == 4) lvl = make_unique<Level4> (seed);
	else lvl = make_unique<NonRandom> (script, level);

	getNextBlock();
	currentBlock = nullptr;
	std::swap(currentBlock, nextBlock);
	currentBlock->attach(&sg);
	currentBlock->notifCurrPos();
}

BasicBoard::~BasicBoard() {}

string BasicBoard::print(bool blind) {
	char type = ' ';
	if (nextBlock) type = nextBlock->getType();
	return sg.print(lvl->getLevel(), score, blind, type);
}

bool BasicBoard::validMove(vector<Coordinates> newPos) {
	for (int i = 0; i < newPos.size(); ++i) {
		int roww = newPos.at(i).row;
		int coll = newPos.at(i).col;
		if ((roww < 0) || (roww > 17) || (coll < 0) || (coll > 10)){
			return false;
		}
		char c = grid.at(roww).at(coll);
		if (c != ' ') return false;
	}
	return true;
}

int abs(int num) {
	if (num < 0) return num * -1;
	return num;
}

void BasicBoard::turnBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->turnPos(amount/abs(amount)));
	cout << valid <<endl;
		if (valid) currentBlock->turn(amount/abs(amount));
		else break;
	}
}

void BasicBoard::moveBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->movePos(amount/abs(amount)));
		if (valid) currentBlock->move(amount/abs(amount));
		else break;
	}
}

void BasicBoard::downBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->downPos(1));
		if (valid) {
			currentBlock->down(1);
		}
		else break;
	}
}

int BasicBoard::dropBlock() {
	// keep dropping
	for (int i = 0; i < gridRows; ++i) {
		bool valid = validMove(currentBlock->downPos(1));
		if (valid) {
			currentBlock->down(1);
		}
		else break;
	}

	// change to block 2
	currentBlock->detach();
	Block2 b2(4,lvl->getLevel());
	activeBlocks.emplace_back(b2);
	vector<Coordinates> blockCoords = currentBlock->getPos();
  for (auto coord:blockCoords) {
		grid[coord.row].changeCell(coord.col, currentBlock->getType());
		grid[coord.row].attachObserver(coord.col, &b2);
	}

	// check lines cleared
	int linesCleared = 0;
	for (int i = gridRows - 1; i >= 0; --i) {
		if (grid[i].checkFull()) {
			++linesCleared;
			grid.erase(grid.begin() + i);
			Row newRow {0, &sg, &gd};
			grid.insert(grid.begin(), newRow);
			for (int j = i; j >= 0; --j) {
				grid[j].changeRowNum(j);
			}
			++i;
		}
	}

	// calculate score
	if (linesCleared > 0)  score += (lvl->getLevel() + linesCleared) * (lvl->getLevel() + linesCleared);
	for (int i = 0; i < activeBlocks.size(); ++i) {
		if (activeBlocks[i].checkDeleted()) {
			score += (activeBlocks[i].getLevelDropped() + 1) * (activeBlocks[i].getLevelDropped() + 1);
			activeBlocks.erase(activeBlocks.begin() + i);
		}
	}

	// switch blocks
	currentBlock = nullptr;
	std::swap(currentBlock, nextBlock);

	// check game over
	if (!validMove(currentBlock->getPos())) {
		currentBlock = nullptr;
		throw "game over";
	}

	currentBlock->attach(&sg);
	currentBlock->notifCurrPos();

	return linesCleared;
}

void BasicBoard::changeLevel(int direction, bool rand, string filename) {
	int level = lvl->getLevel();
	if (direction == 0 && rand) {
		if (level == 1) lvl = make_unique<Level1> (seed);
		else if (level == 2) lvl = make_unique<Level2> (seed);
		else if (level == 3) lvl = make_unique<Level3> (seed);
		else if (level == 4) lvl = make_unique<Level4> (seed);
	} else if (direction == 0 && !rand) {
		lvl = make_unique<NonRandom> (filename, lvl->getLevel());
	} else if (direction != 0) {
		int newLevel = lvl->getLevel() + direction;
		if (newLevel < 0 || newLevel > maxLevel) return;
		if (newLevel == 1) lvl = make_unique<Level1> (seed);
		else if (newLevel == 2) lvl = make_unique<Level2> (seed);
		else if (newLevel == 3) lvl = make_unique<Level3> (seed);
		else if (newLevel == 4) lvl = make_unique<Level4> (seed);
	}
}

int BasicBoard::getScore() { return score; }

void BasicBoard::getNextBlock() {
	if (!nextBlock) {
		char type = lvl->nextBlock();
		if (type == 'I') nextBlock = make_unique<I>();
		else if (type == 'J') nextBlock = make_unique<J>();
		else if (type == 'L') nextBlock = make_unique<L>();
		else if (type == 'O') nextBlock = make_unique<O>();
		else if (type == 'S') nextBlock = make_unique<S>();
		else if (type == 'Z') nextBlock = make_unique<Z>();
		else nextBlock = make_unique<T>();
	}
}

bool BasicBoard::inSpecialEffect() {
	return specialEffect;
}

void BasicBoard::setSpecialEffect(bool se) {
	specialEffect = se;
}

int BasicBoard::getLevel() { return lvl->getLevel(); }

bool BasicBoard::originalPos() { return currentBlock->origPos(); }

bool BasicBoard::validDownPos() {
	if (!validMove(currentBlock->downPos(1))) return false;
	return true;
}

bool BasicBoard::validStartPos() {
	return validMove(currentBlock->getPos());
}

void BasicBoard::changeCurrentBlock(char type) {
	if (type == 'I') nextBlock = make_unique<I>();
	else if (type == 'J') nextBlock = make_unique<J>();
	else if (type == 'L') nextBlock = make_unique<L>();
	else if (type == 'O') nextBlock = make_unique<O>();
	else if (type == 'S') nextBlock = make_unique<S>();
	else if (type == 'Z') nextBlock = make_unique<Z>();
	else nextBlock = make_unique<T>();
}
