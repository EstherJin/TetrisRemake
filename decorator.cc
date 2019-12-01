#include "board.h"
#include "decorator.h"
using namespace std;

Decorator::Decorator(Board *b): board {b} {}

Decorator::~Decorator() {}

std::string print(bool blind) override {
	board->print(blind);
}
void turnBlock(int amount) override {
	board->turnBlock(amount);
}
void moveBlock(int amount) override {
	board->moveBlock(amount);
}
void downBlock(int amount) override {
	board->downBlock(amount);
}
int dropBlock() override {
	board->dropBlock();
}
void changeLevel(int direction, bool random, std::string filename) override {
	board->changeLevel(direction, random, filename);
}
int getScore() override {
	board->getScore();
}
void getNextBlock() override {
	board->getNextBlock();
}
bool validMove(vector<Coordinates> newPos) override {
	board->validMove(newPos);
}
bool inSpecialEffect() override {
	board->inSpecialEffect();
}
