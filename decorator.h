#ifndef DECORATOR_H
#define DECORATOR_H
#include "board.h"

class Decorator:public Board {
protected:
	Board *board;
public:
	Decorator(Board *b);
	virtual ~Decorator();
};

#endif