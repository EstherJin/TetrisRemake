#include "block1.h"
using namespace std;

Block1::Block1(int position, char c): position{position}, c{c}{}

Block1::~Block1(){}

char Block1::getType(){
  return c;
}

vector<Coordinates> Block1::getPos(){
  return coords;
}

bool Block1::origPos(){
  return (position == 0);
}

void Block1::move(int shift){
  for (int i = 0; i < 4; ++i){
    State stat = {' ', coords, false};
    setState(stat);
    notifyObservers();
    coords.at(i).col += shift;
    stat = {c, coords, true};
    setState(stat);
    notifyObservers();
  }
}

vector<Coordinates> Block1::movePos(int shift){
  vector<Coordinates> cds = coords;
  for (int i = 0; i < 4; ++i){
    cds.at(i).col += shift;
  }
  return cds;
}

void Block1::down(int shift){
  int size = coords.size();
  for (int i = 0; i < size; ++i){
    State stat = {' ', coords, false};
    setState(stat);
    notifyObservers();
    coords.at(i).row += shift;
    stat = {c, coords, true};
    setState(stat);
    notifyObservers();
  }
}

vector<Coordinates> Block1::downPos(int shift){
  vector<Coordinates> cds = coords;
  int size = coords.size();
  for (int i = 0; i < size; ++i){
    cds.at(i).row += shift;
  }
  return cds;
}
