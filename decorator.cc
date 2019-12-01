#include "board.h"
#include "decorator.h"
using namespace std;

Decorator::Decorator(Board *b): board {b} {}

Decorator::~Decorator() {}

std::string Decorator::print(bool blind) override {
	board->print(blind);
}
void Decorator::turnBlock(int amount) override {
	board->turnBlock(amount);
}
void Decorator::moveBlock(int amount) override {
	board->moveBlock(amount);
}
void Decorator::downBlock(int amount) override {
	board->downBlock(amount);
}
int Decorator::dropBlock() override {
	board->dropBlock();
}
void Decorator::changeLevel(int direction, bool random, std::string filename) override {
	board->changeLevel(direction, random, filename);
}
int Decorator::getScore() override {
	board->getScore();
}
void Decorator::getNextBlock() override {
	board->getNextBlock();
}
bool Decorator::validMove(vector<Coordinates> newPos) override {
	board->validMove(newPos);
}
bool Decorator::inSpecialEffect() override {
	board->inSpecialEffect();
}
void Decorator::setSpecialEffect(bool se) override {
	board->setSpecialEffect(se);
}
