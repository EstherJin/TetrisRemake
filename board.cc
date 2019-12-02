#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"
#include "block1.h"
#include "block2.h"
#include "Level.h"
#include "stringGenerator.h"
#include "coordinates.h"
#include "board.h"
using namespace std;

Board(bool random, int level = 0, bool textOnly = false, string script = "", unsigned seed = 0): random{random} {
	for (int r = 0; r < gridRows; ++r) {
		Row row{r, &sg};
		grid.emplace_back(row);
	}

	if (level == 1) lvl = make_unique<Level1> {level};
	else if (level == 2) lvl = make_unique<Level2> {level};
	else if (level == 3) lvl = make_unique<Level3> {level};
	else if (level == 4) lvl = make_unique<Level4> {level};
	else lvl = make_unique<NonRandom> {script, level};

	currentBlock = make_unique<Block1> {lvl->nextBlock()};
	nextBlock = nullptr;
}

Board::~Board() {}

string Board::print(bool blind) {
	char type = ' ';
	if (nextBlock) type = nextBlock->getType();
	return sg->print(lvl->getLevel(), score, blind, type);
}

bool Board::validMove(vector<Coordinates> newPos) {
	for (int i = 0; i < newPos.size(); ++i) {
		int roww = newPos.at(i).row;
		int coll = newPOs.at(i).col;
		if ((roww < 0) || (row > 17) || (coll < 0) || (coll > 10)){
			return false;
		}
		char c = grid[roww].at(coll);
		if (c != ' ') return false;
	}
	return true;
}

int abs(int num) {
	if (num < 0) return num * -1;
	return num;
}

void Board::turnBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->turnPos(amount/abs(amount)));
		if (valid) currentBlock->turn(amount/abs(amount));
		else break;
	}
}

void Board::moveBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->movePos(amount/abs(amount)));
		if (valid) currentBlock->move(amount/abs(amount));
		else break;
	}
}

void Board::downBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->downPos(1));
		if (valid) {
			currentBlock->down(1);
		}
		else break;
	}
}

int Board::dropBlock() {
	// keep dropping
	for (int i = 0; i < gridRows; ++i) {
		bool valid = validMove(currentBlock->downPos(1));
		if (valid) {
			currentBlock->down(1);
		}
		else break;
	}

	// change to block 2
	Block2 b2;
	activeBlocks.emplace_back(b2);
	vector<Coordinates> blockCoords = currentBlock->getPos();
	for (auto coord:blockCoords) {
		grid[(*coord).row].changeCell((*coord).col, currentBlock->getType());
		grid[(*coord).row].attachObserver((*coord).col, &activeBlocks.back());
	}

	// check lines cleared
	int linesCleared = 0;
	for (int i = gridRows - 1; i >= 0; --i) {
		if (grid[i].checkFull()) {
			++linesCleared;
			grid.erase(grid.begin() + i);
			Row newRow {0, &sg};
			grid.emplace_front(newRow);
			for (int j = i; j >= 0; --j) {
				grid[j].changeRowNum(j);
			}
		}
	}

	// calculate score
	score += (lvl->getLevel() + linesCleared) * (lvl->getLevel() + linesCleared);
	for (int i = 0; i < activeBlocks.size(); ++i) {
		if (activeBlocks[i].checkDeleted()) {
			score += (activeBlocks[i].getLevelDropped() + 1) * (activeBlocks[i].getLevelDropped() + 1);
			activeBlocks.erase(activeBlocks.begin() + i);
		}
	}

	// switch blocks
	currentBlock = nullptr;
	std::swap(currentBlock, nextBlock);

	return linesCleared;
}

void Board::changeLevel(int direction, bool rand, string filename) {
	if (direction == 0 && rand) {
		if (level == 1) lvl = make_unique<Level1> {lvl->getLevel()};
		else if (level == 2) lvl = make_unique<Level2> {lvl->getLevel()};
		else if (level == 3) lvl = make_unique<Level3> {lvl->getLevel()};
		else if (level == 4) lvl = make_unique<Level4> {lvl->getLevel()};
	} else if (direction == 0 && !rand) {
		lvl = make_unique<NonRandom> {lvl->getLevel(), filename};
	} else if (direction != 0) {
		int newLevel = lvl->getLevel() + direction;
		if (newLevel < 0 || newLevel > maxLevel) return;
		lvl->changeLevel(newLevel);
	}
}

int Board::getScore() { return score; }

void Board::getNextBlock() {
	if (!nextBlock) nextBlock = make_unique<Block1> {lvl->nextBlock()};
}

bool Board::inSpecialEffect() {
	return specialEffect;
}

void Board::setSpecialEffect(bool se) {
	return specialEffect;
}
