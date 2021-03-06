#include "block1.h"
using namespace std;

Block1::Block1(int position, char c): position{position}, c{c}{}

Block1::~Block1(){
  for (int i = 0; i < coords.size(); ++i){
    State stat = {' ', coords[i], false};
    setState(stat);
    notifyObservers();
  }
}

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
  for (int i = 0; i < coords.size(); ++i){
    State stat = {' ', coords[i], false};
    setState(stat);
    notifyObservers();
  }
  for (int i = 0; i < coords.size(); ++i){
    coords.at(i).col += shift;
    State stat = {c, coords[i], true};
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
    State stat = {' ', coords[i], false};
    setState(stat);
    notifyObservers();
  }
  for (int i = 0; i < coords.size(); ++i){
    coords.at(i).row += shift;
    State stat = {c, coords[i], true};
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

void Block1::notifCurrPos(){
  int size = coords.size();
  for (int i = 0; i < size; ++i){
    State stat = {c, coords[i], true};
    setState(stat);
    notifyObservers();
  }
}

int Block1::getNum(){
  return coords.size();
}
