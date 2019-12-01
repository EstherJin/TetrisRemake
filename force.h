#ifndef FORCE_H
#define FORCE_H
#include "decorator.h"

class Force:public Decorator {
public:
	Force(Board *b);
	int dropBlock () override;
};

#endif