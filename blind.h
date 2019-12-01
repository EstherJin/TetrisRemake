#ifndef BLIND_H
#define BLIND_H
#include "decorator.h"

class Blind:public Decorator {
public:
	Blind(Board *b);
	void print(bool blind) override;
};

#endif