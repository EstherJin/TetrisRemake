#ifndef I_H
#define I_H
#include "block1.h"
using namespace std;

class I: public Block1 {
public:
  I();
  ~I(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
