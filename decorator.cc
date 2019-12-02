#include <memory>
#include "board.h"
#include "decorator.h"
using namespace std;

Decorator::Decorator(Board *b): board {b} {}

Decorator::~Decorator() {}

std::string Decorator::print(bool blind) {
	board->print(blind);
}
void Decorator::turnBlock(int amount) {
	board->turnBlock(amount);
}
void Decorator::moveBlock(int amount) {
	board->moveBlock(amount);
}
void Decorator::downBlock(int amount) {
	board->downBlock(amount);
}
int Decorator::dropBlock() {
	board->dropBlock();
}
void Decorator::changeLevel(int direction, bool random, std::string filename) {
	board->changeLevel(direction, random, filename);
}
int Decorator::getScore() {
	board->getScore();
}
void Decorator::getNextBlock() {
	board->getNextBlock();
}
bool Decorator::validMove(vector<Coordinates> newPos) {
	board->validMove(newPos);
}
bool Decorator::inSpecialEffect() {
	board->inSpecialEffect();
}
void Decorator::setSpecialEffect(bool se) {
	board->setSpecialEffect(se);
}
Board *Decorator::removeDecorator() {
	Board *tmp = board.get();
	board = nullptr;
	return tmp;
}
int Decorator:: getLevel() { board->getLevel(); }
