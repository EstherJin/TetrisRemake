#include "board.h"
#include "decorator.h"
#include "heavy.h"
using namespace std;

Heavy::Heavy(Board *b): Decorator{b} {}

bool validMove(vector<Coordinates> newPos) {
	for (int i = 0; i < newPos.size(); ++i) {
		char c = grid[Coordinates.row].at(Coordinates.col);
		if (c != ' ') return false;
	}
	return true;
}

void Heavy::moveBlock(int amount) override {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(board->currentBlock->movePos(amount/abs(amount)));
		if (valid) board->currentBlock->move(amount/abs(amount));
		else break;
	}
	board->downBlock(2);
}

void Heavy::downBlock(int amount) override {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(board->currentBlock->downPos(1));
		if (valid) {
			board->currentBlock->down(1);
		}
		else board->dropBlock();
	}
}
