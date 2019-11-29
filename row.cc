#include "row.h"
using namespace std;

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

char Row::at(int col){
  return roww.at(col).getChar();
}
