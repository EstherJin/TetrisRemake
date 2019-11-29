#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "cell.h"
#include "block1.h"
#include "block2.h"
#include "level.h"
#include "coordinates.h"
#include "board.h"
using namespace std;

Board::Board(int level) {
	for (int r = 0; r < gridRows; ++r) {
		Row row{r, &sg};
		grid.emplace_back(row);
	}

	if (level == 1) lvl {new Level1 {level}};
	else if (level == 2) lvl {new Level2 {level}};
	else if (level == 3) lvl {new Level3 {level}};
	else if (level == 4) lvl {new Level4 {level}};
	else lvl {new NonRandom{level}};

	currentBlock{new Block1 {lvl->nextBlock()}};
	nextBlock = nullptr;
}

Board::~Board() {}

string Board::print(bool blind) {
	char type = ' ';
	if (nextBlock) type = nextBlock->getType();
	return sg->print(lvl->getLevel(), score, blind, type);
}

bool validMove(vector<Coordinates> newPos) {
	for (int i = 0; i < newPos.size(); ++i) {
		char c = grid[Coordinates.row].at(Coordinates.col);
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
	// TO DO:
}

void Board::changeLevel(int direction, bool random, string filename) {
	if (random) {
		if (level == 1) lvl {new Level1 {lvl->getLevel()}};
		else if (level == 2) lvl {new Level2 {lvl->getLevel()}};
		else if (level == 3) lvl {new Level3 {lvl->getLevel()}};
		else if (level == 4) lvl {new Level4 {lvl->getLevel()}};
	} else {
		lvl {new NonRandom{lvl->getLevel(), filename}};
	}
}

int Board::getScore() { return score; }

void Board::getNextBlock() {
	nextBlock = new Block1 {lvl->nextBlock()};
}