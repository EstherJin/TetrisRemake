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
#include "row.h"

class Block1;

class Board {
	StringGenerator sg;
	std::vector<Row> grid;
	std::vector<Block2> activeBlocks;
	int score = 0;
	std::unique_ptr<Level> lvl;
	std::unique_ptr<Block1> nextBlock;
protected:
	const gridRows = 18;
	std::unique_ptr<Block1> currentBlock;
	bool specialEffect = false;
public:
	Board(int level = 0, bool textOnly = false, std::string script = "", unsigned seed = 0);
	virtual ~Board() = 0;
	virtual std::string print(bool blind = false);
	virtual void turnBlock(int amount);
	virtual void moveBlock(int amount);
	virtual void downBlock(int amount);
	virtual int dropBlock(); // returns number of lines cleared
	virtual void changeLevel(int direction, bool random, std::string filename);
	virtual int getScore();
	virtual void getNextBlock();
	virtual bool validMove(vector<Coordinates> newPos);
	virtual bool inSpecialEffect();
};

#endif
