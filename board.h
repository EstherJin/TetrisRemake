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
public:
	Board();
	virtual ~Board();
	virtual std::string print(bool blind = false)=0;
	virtual void turnBlock(int amount)=0;
	virtual void moveBlock(int amount)=0;
	virtual void downBlock(int amount)=0;
	virtual int dropBlock()=0; // returns number of lines cleared
	virtual void changeLevel(int direction, bool rand, std::string filename)=0;
	virtual int getScore()=0;
	virtual void getNextBlock()=0;
	virtual bool validMove(vector<Coordinates> newPos)=0;
	virtual bool inSpecialEffect()=0;
	virtual void setSpecialEffect(bool se = true)=0;
	virtual int getLevel()=0;
	virtual bool originalPos() = 0;
	virtual bool validDownPos() = 0;
	virtual bool validStartPos() = 0;
};

#endif
