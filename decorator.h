#ifndef DECORATOR_H
#define DECORATOR_H
#include "board.h"

class Decorator:public Board {
protected:
	Board *board;
public:
	Decorator(Board *b);
	virtual ~Decorator();
	virtual std::string print(bool blind = false) override;
	virtual void turnBlock(int amount) override;
	virtual void moveBlock(int amount) override;
	virtual void downBlock(int amount) override;
	virtual int dropBlock() override; // returns number of lines cleared
	virtual void changeLevel(int direction, bool random, std::string filename) override;
	virtual int getScore() override;
	virtual void getNextBlock() override;
	virtual bool validMove(vector<Coordinates> newPos) override;
	virtual bool inSpecialEffect() override;

	Board *removeDecorator();
};

#endif