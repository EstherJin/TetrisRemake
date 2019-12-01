#include <memory>
#include "board.h"
#include "decorator.h"
#include "force.h"
using namespace std;

Force::Force(Board *b, char changeBlockType): Decorator{b} {
	board->currentBlock = make_unique<Block1> {0, changeBlockType};
}

int Force::dropBlock () override {
	if (board->currentBlock->origPos()) {
		int lines = board->dropBlock();
		return lines;
	} else {
		// TO DO: game over? Throw exception?
	}
}
