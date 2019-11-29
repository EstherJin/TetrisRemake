#include "o.h"
using namespace std;

O::O(): Block1{0, 'O'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
}

void O::turn(int shift){}

vector<Coordinates> O::turnPos(int shift){
  return coords;
}
