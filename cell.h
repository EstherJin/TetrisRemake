#ifndef SUBJECT_H
#define SUBJECT_H
#include "subject.h"

class Cell: public Subject {
  char type;
 public:
  void clearCell();
  void changeCell(char changeTo);
};

void Cell::clearCell(){
  type = ' ';
  State stat =
}

void Cell::changeCell(char changeTo);
