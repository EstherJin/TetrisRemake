#include "board.h"
#include "decorator.h"
#include "force.h"
using namespace std;

Force::Force(Board *b): Decorator{b} {}

int Force::dropBlock () override {
	if (board->currentBlock->origPos()) {
		int lines = board->dropBlock();
		return lines;
	} else {
		// TO DO: game over? Throw exception?
	}
}
