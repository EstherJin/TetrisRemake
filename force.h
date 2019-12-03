#ifndef FORCE_H
#define FORCE_H
#include "decorator.h"

class Force:public Decorator {
public:
	Force(std::shared_ptr<Board> b, char changeBlockType);
	int dropBlock () override;
};

#endif