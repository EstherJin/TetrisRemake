#ifndef ROW_H
#define ROW_H
#include "cell.h"

class Row {
  vector<Cell> roww;
  int rowNum;
 public:
  Row(int rowNum, Observer *ob);
  ~Row();
  bool checkFull();
  void changeRowNum(int row);
  void changeCell(int col, char changeTo);
  void attachObserver(int col, Observer *ob);
  void detachObserver(int col);
  char at(int col);
};

#endif
