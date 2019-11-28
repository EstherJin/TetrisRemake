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
  char at(int col);
};

Row::Row(int rowNum,  Observer *ob): rowNum{rowNum}{
  for(int i = 0; i < 11; ++i){
    Cell c = {' ', rowNum, i};
    c.attach(ob);
    roww.emplace_back(c);
  }
}

Row::~Row(){
  for(int i = 0; i < 11; ++i){
    roww.at(i).clearCell();
  }
}

bool Row::checkFull(){
  for(int i = 0; i < 11; ++i){
    if (roww.at(i).getChar() == ' '){
      return false;
    }
  }
  return true;
}

void Row::changeRowNum(int row){
  for(int i = 0; i < 11; ++i){
    roww.at(i).changerow(row);
  }
}

void Row::changeCell(int col, char changeTo){
  roww.at(col).changeCell(changeTo);
}

char at(int col){
  return roww.at(col).getChar();
}

#endif
