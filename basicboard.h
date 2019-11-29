#ifndef BASICBOARD_H
#define BASICBOARD_H
#include "board.h"

class BasicBoard:public Board {
	BasicBoard(int level): Board{level} {}
};

#endif