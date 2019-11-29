#ifndef DOT_H
#define DOT_H
#include "block1.h"
using namespace std;

class Dot: public Block1 {
public:
  Dot();
  ~Dot(){}
  void move(int shift);
  void turn(int shift);
  vector<Coordinates> movePos(int shift);
  vector<Coordinates> turnPos(int shift);
};

#endif
