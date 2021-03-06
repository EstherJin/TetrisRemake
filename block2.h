#ifndef BLOCK2_H
#define BLOCK2_H
#include "observer.h"
using namespace std;

class Block2: public Observer{
private:
  int cellCount;
  int levelDropped;
public:
  Block2(int cellCount, int levelDropped);
  virtual ~Block2();
  bool checkDeleted();
  int getLevelDropped();
  void notify(Subject &whoFrom) override;
};

#endif
