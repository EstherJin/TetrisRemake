#ifndef CELL_H
#define CELL_H
#include "subject.h"
#include "coordinates.h"

class Cell: public Subject {
  char type;
  Coordinates coords;
 public:
  Cell(char type, int row, int col);
  ~Cell();
  void clearCell();
  void changeCell(char changeTo);
  void changerow(int row);
  char getChar();
};


#endif
