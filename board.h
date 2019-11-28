#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "cell.h"
#include "block2.h"
#include "level.h"

class Block1;

class Board {
	const gridRows = 18;
	const gridColumns = 11;
	std::vector<std::vector<Cell>> grid;
	std::vector<Block2> activeBlocks;
	int score = 0;
	Level lvl;
	std::unique_ptr<Block1> currentBlock;
	std::unique_ptr<Block1> nextBlock;
	std::unique_ptr<StringGenerator> sg;
public:
	Board(int level = 0);
	virtual ~Board() = 0;
	std::string print(bool blind);
	void turnBlock(int amount);
	void moveBlock(int amount);
	void downBlock(int amount);
	int dropBlock(); // returns number of lines cleared
	void changeLevel(int direction, bool random, std::string filename);
	int getScore();
	void getNextBlock();
};

#endif