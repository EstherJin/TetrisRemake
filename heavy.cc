#include "board.h"
#include "decorator.h"
#include "heavy.h"
using namespace std;

Heavy::Heavy(Board *b): Board{}, Decorator{b} {}

void Heavy::moveBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = board->validMove(board->currentBlock->movePos(amount/abs(amount)));
		if (valid) board->currentBlock->move(amount/abs(amount));
		else break;
	}
	board->downBlock(2);
}

void Heavy::downBlock(int amount) {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = board->validMove(board->currentBlock->downPos(1));
		if (valid) {
			board->currentBlock->down(1);
		}
		else board->dropBlock();
	}
}
