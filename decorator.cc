#include <memory>
#include "board.h"
#include "decorator.h"
using namespace std;

Decorator::Decorator(shared_ptr<Board> b): board {b} {}

Decorator::~Decorator() {}

std::string Decorator::print(bool blind) {
	return board->print(blind);
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
shared_ptr<Board> Decorator::removeDecorator() {
	board->setSpecialEffect(false);
	return board;
}
int Decorator::getLevel() { board->getLevel(); }

bool Decorator::originalPos() { return board->originalPos(); }

bool Decorator::validDownPos() {
	return board->validDownPos();
}

bool Decorator::validStartPos() {
	return board->validStartPos();
}

void Decorator::changeCurrentBlock(char type) {
	board->changeCurrentBlock(type);
}