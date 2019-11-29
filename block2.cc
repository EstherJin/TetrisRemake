#include "state.h"
#include "subject.h"
#include "cell.h"
using namespace std;

Block2::Block2(int cellCount, int levelDropped): cellCount{cellCount}, levelDropped{levelDropped}{}

Block2::~Block2(){}

bool Block2::checkDeleted(){
  return (cellCount == 0);
}

int Block2::getLevelDropped(){
  return levelDropped;
}

void Block2::notify(Subject &whoFrom){
  State stat = whofrom.getState();
  if (!stat.add){
    --cellCount;
  }
}
