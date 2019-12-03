#include "board.h"
#include "decorator.h"
#include "blind.h"
#include "block1.h"
using namespace std;

Blind::Blind(Board *b): Board{}, Decorator{b} {}

string Board::print(bool blind) {
	board->print(true);
}
