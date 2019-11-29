#include "dot.h"
using namespace std;


Dot::Dot(): Block1{0, '*'} {
  coords.emplace_back(Coordinates {3,5});
}

void Dot::move(int shift){}

vector<Coordinates> Dot::movePos(int shift){
  return coords;
}

void Dot::turn(int shift){}

vector<Coordinates> Dot::turnPos(int shift){
  return coords;
}
