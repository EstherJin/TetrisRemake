#ifndef S_H
#define S_H
#include "block1.h"
using namespace std;

class S: public Block1 {
public:
  S();
  ~S(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
