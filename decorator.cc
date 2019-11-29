#include "board.h"
#include "decorator.h"
using namespace std;

Decorator::Decorator(Board *b): board {b} {}

Decorator::~Decorator() {} // how to remove decorator and keep board?
