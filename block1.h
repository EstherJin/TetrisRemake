#ifndef BLOCK1_H
#define BLOCK1_H
#include <vector>
#include "coords.h"
#include "subject.h"
using namespace std;

class Block1{
protected:
  vector<Coordinates> coords;
  int position;
  char c;
public:
  Block1(int position, char c);
  virtual ~Block1();
  virtual void move(int shift);
  virtual void turn(int shift)=0;
  void down(int shift);
  virtual vector<Coordinates> movePos(int shift);
  virtual vector<Coordinates> turnPos(int shift)=0;
  vector<Coordinates> downPos(int shift);
  char getType();
  vector<Coordinates> getPos();
};

#endif
