#ifndef BLIND_H
#define BLIND_H
#include "decorator.h"

class Blind:public Decorator {
public:
	Blind(std::shared_ptr<Board> board);
	std::string print(bool blind) override;
};

#endif
