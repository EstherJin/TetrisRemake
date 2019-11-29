#ifndef O_H
#define O_H
#include "block1.h"
using namespace std;

class O: public Block1 {
public:
  O();
  ~O(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

#endif
