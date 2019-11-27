#ifndef BLOCK2_H
#define BLOCK2_H
#include "observer.h"
using namespace std;

class Block2: public Observer{
private:
  int cellCount;
  int levelDropped;
public:
  Block2();
  virtual ~Block2();
  bool checkDeleted();
  int getLevelDropped();
  void notify(Subject &whoFrom) override;
};

#include "state.h"
#include "subject.h"

Block2::Block2(int cellCount, int levelDropped): cellCount{cellCount}, levelDropped{levelDropped}{}

Block2::~Block2(){}

bool Block2::checkDeleted(){
  return (cellCount == 0);
}

int Block2::getLevelDropped(){
  return levelDropped;
}

void notify(Subject &whoFrom){
  State stat = whofrom.getState();
  if (!stat.add){
    --cellCount;
  }
}

#endif
