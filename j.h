#ifndef J_H
#define J_H
#include "block1.h"
using namespace std;

class J: public Block1 {
public:
  J();
  ~J(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
