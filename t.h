#ifndef T_H
#define T_H
#include "block1.h"
using namespace std;

class T: public Block1 {
public:
  T();
  ~T(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
