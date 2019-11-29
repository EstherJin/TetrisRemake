#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "cell.h"
#include "block2.h"
#include "level.h"
#include "stringgenerator.h"

class Block1;
class Row;

class Board {
	const gridRows = 18;
	StringGenerator sg;
	std::vector<Row> grid;
	std::vector<Block2> activeBlocks;
	int score = 0;
	std::unique_ptr<Level> lvl;
	std::unique_ptr<Block1> currentBlock;
	std::unique_ptr<Block1> nextBlock;
public:
	Board(int level = 0);
	virtual ~Board() = 0;
	virtual std::string print(bool blind);
	void turnBlock(int amount);
	virtual void moveBlock(int amount);
	virtual void downBlock(int amount);
	int dropBlock(); // returns number of lines cleared
	void changeLevel(int direction, bool random, std::string filename);
	int getScore();
	void getNextBlock();
};

#endif