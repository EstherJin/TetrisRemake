#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "cell.h"
#include "block2.h"
#include "Level.h"
#include "stringGenerator.h"
#include "row.h"

class Block1;

class Board {
	StringGenerator sg;
	std::vector<Row> grid;
	std::vector<Block2> activeBlocks;
	int score = 0;
	std::unique_ptr<Level> lvl;
	std::unique_ptr<Block1> nextBlock;
	bool random;
	const maxLevel = 4;
protected:
	const int gridRows = 18;
	std::unique_ptr<Block1> currentBlock;
	bool specialEffect = false;
public:
	Board(bool random, int level = 0, bool textOnly = false, std::string script = "", unsigned seed = 0);
	virtual ~Board() = 0;
	virtual std::string print(bool blind = false);
	virtual void turnBlock(int amount);
	virtual void moveBlock(int amount);
	virtual void downBlock(int amount);
	virtual int dropBlock(); // returns number of lines cleared
	virtual void changeLevel(int direction, bool rand, std::string filename);
	virtual int getScore();
	virtual void getNextBlock();
	virtual bool validMove(vector<Coordinates> newPos);
	virtual bool inSpecialEffect();
	virtual void setSpecialEffect(bool se = true);
};

#endif
