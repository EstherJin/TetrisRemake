#ifndef INTERPRET_H
#define INTERPRET_H
#include <vector>
#include <map>
#include <string>
using namespace std;

class Game;

class Interpreter {
  map<string, vector<string>> commands;
public:
  Interpreter();
  void processCommands(string cmd, Game *g, int *turn);
};

#endif
