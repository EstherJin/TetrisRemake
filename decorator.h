#ifndef DECORATOR_H
#define DECORATOR_H
#include <memory>
#include "board.h"

class Decorator:public Board {
protected:
	std::shared_ptr<Board> board;
public:
	Decorator(shared_ptr<Board> b);
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
	virtual void setSpecialEffect(bool se = true) override;
	virtual int getLevel() override;

	Board *removeDecorator();
};

#endif