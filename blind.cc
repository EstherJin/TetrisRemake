#include "board.h"
#include "decorator.h"
#include "blind.h"
#include "block1.h"
using namespace std;

Blind::Blind(shared_ptr<Board> board): Decorator{board} {}

string Blind::print(bool blind) {
	board->print(true);
}
