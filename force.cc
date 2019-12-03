#include <memory>
#include "board.h"
#include "decorator.h"
#include "force.h"
using namespace std;

Force::Force(shared_ptr<Board> board, char changeBlockType): Decorator{board} {
	board->currentBlock = make_unique<Block1> (0, changeBlockType);
}

int Force::dropBlock () {
	if (board->originalPos()) {
		int lines = board->dropBlock();
		return lines;
	} else {
		throw "game over";
	}
}
