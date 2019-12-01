#include "board.h"
#include "decorator.h"
#include "blind.h"
using namespace std;

Blind::Blind(Board *b): Decorator{b} {}

string Board::print(bool blind) {
	char type = ' ';
	if (nextBlock) type = nextBlock->getType();
	return sg->print(lvl->getLevel(), score, true, type);
}
