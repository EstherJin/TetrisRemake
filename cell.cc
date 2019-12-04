#include "cell.h"
using namespace std;

Cell::Cell(char type, int row, int col): type{type}{
  Coordinates c = {row, col};
  coords = c;
}

Cell::~Cell(){
  type = ' ';
  State stat = {' ', coords, false};
  setState(stat);
  notifyObservers();
}

void Cell::clearCell(){
  type = ' ';
  State stat = {' ', coords, false};
  setState(stat);
  notifyObservers();
}

void Cell::changeCell(char changeTo){
  type = changeTo;
  State stat = {changeTo, coords, true};
  setState(stat);
  notifyObservers();
}

void Cell::changerow(int row){
  State stat = {' ', coords, false};
  setState(stat);
  notifyObservers();
  coords.row = row;
  stat = {type, coords, true};
  setState(stat);
  notifyObservers();
}

char Cell::getChar(){
  return type;
}

void Cell::notif(){
  stat = {type, coords, true};
  setState(stat);
  notifyObservers();
}
