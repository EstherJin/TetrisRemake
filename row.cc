#include "row.h"
using namespace std;

Row::Row(int rowNum,  Observer *ob, Observer *ob2): rowNum{rowNum}{
  for(int i = 0; i < 11; ++i){
    Cell c = {' ', rowNum, i};
    c.attach(ob);
	c.attach(ob2); 
    roww.emplace_back(c);
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

void Row::attachObserver(int col, Observer *ob){
  roww.at(col).attach(ob);
}

void Row::detachObserver(int col){
  roww.at(col).detach();
}

char Row::at(int col){
  return roww.at(col).getChar();
}
