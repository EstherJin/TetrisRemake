#ifndef HEAVY_H
#define HEAVY_H
#include "decorator.h"

class Heavy:public Decorator {
public:
	Heavy(Board *b);
	void moveBlock(int amount) override;
	void downBlock(int amount) override;
};

#endif