#ifndef BASICBOARD_H
#define BASICBOARD_H
#include "board.h"

class BasicBoard:public Board {
	BasicBoard(int level = 0, bool textOnly = false, string script = "", unsigned seed = 0): Board{level, textOnly, script, seed} {}
};

#endif