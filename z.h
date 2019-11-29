#ifndef Z_H
#define Z_H
#include "block1.h"
using namespace std;

class Z: public Block1 {
public:
  Z();
  ~Z(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
