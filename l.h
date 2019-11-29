#ifndef L_H
#define L_H
#include "block1.h"
using namespace std;

class L: public Block1 {
public:
  L();
  ~L(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
