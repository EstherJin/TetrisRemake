#include "board.h"
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
		bool valid = validMove(currentBlock->movePos(amount/abs(amount)));
		if (valid) currentBlock->move(amount/abs(amount));
		else break;
	}
	downBlock(2);
}

void Heavy::downBlock(int amount) override {
	for (int i = 0; i < abs(amount); ++i) {
		bool valid = validMove(currentBlock->downPos(1));
		if (valid) {
			currentBlock->down(1);
		}
		else dropBlock();
	}
}
