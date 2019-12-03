#ifndef ROW_H
#define ROW_H
#include "cell.h"

class Row {
  std::vector<Cell> roww;
  int rowNum;
 public:
  Row(int rowNum, Observer *ob, Observer *ob2);
  bool checkFull();
  void changeRowNum(int row);
  void changeCell(int col, char changeTo);
  void attachObserver(int col, Observer *ob);
  void detachObserver(int col);
  char at(int col);
};

#endif
