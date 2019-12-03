#ifndef _STRINGGENERATOR_H_
#define _STRINGGENERATOR_H_
#include <vector>
#include <string>
#include "observer.h"

class Cell;
class Subject;

class StringGenerator: public Observer {
  std::vector<std::vector<char>> grid;
  const int gridRows = 18;
  const int gridCols = 11;

 public:
  StringGenerator();

  void notify(Subject &whoNotified) override;

  std::string print(int level, int score, bool blind, char next);
};

#endif
