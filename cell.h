#ifndef CELL_H
#define CELL_H
#include "subject.h"
#include "coordinates.h"

class Cell: public Subject {
  char type;
  Coordinates coords,
 public:
  Cell(char type, int row, int col);
  void clearCell();
  void changeCell(char changeTo);
  void changerow(int row);
  char getChar();
};

Cell::Cell(char type, int row, int col): type{type}{
  Coordinates c = {row, col};
  coords = c;
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
  State stat = {type, coords, true};
  setState(stat);
  notifyObservers();
}

char getChar(){
  return type;
}
#endif
