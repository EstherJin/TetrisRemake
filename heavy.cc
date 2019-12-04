#include "board.h"
#include "decorator.h"
#include "heavy.h"
using namespace std;

Heavy::Heavy(shared_ptr<Board> board): Decorator{board} {}

void Heavy::moveBlock(int amount) {
	board->moveBlock(amount);
	downBlock(2);
}

void Heavy::downBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = board->validDownPos();
		if (valid) {
			board->downBlock(1);
		}
		else {
			int linesCleared = board->dropBlock();
			throw linesCleared;
		}
	}
}
