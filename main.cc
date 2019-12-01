#include <iostream>
#include <string>
#include "game.h"
#include "interpreter.h"
using namespace std;


int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  bool textOnly = false;
  int startlvl = 0;
  string script1 = "sequence1.txt"
  string script2 = "sequence2.txt"
  unsigned int seed = 1;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == "-text"){
      textOnly = true;
    } else if (argv[i] == "-startlevel"){
      ++i;
      if (i < argc){
        startlvl = stoi(argv[i]);
        if (!((startlvl >= 0) && (startlvl <= 4))) {
          startlvl = 0;
        }
      }
    } else if (argv[i] == "-scriptfile1"){
      ++i;
      if (i < argc){
        script1 = argv[i];
      }
    } else if (argv[i] == "-scriptfile2"){
      ++i;
      if (i < argc){
        script2 = argv[i];
      }
    } else if (argv[i] == "-seed"){
      ++i;
      if (i < argc){
        int seedd = stoi(argv[i]);
        if (seedd >= 0) {
          seed = seedd;
        }
      }
    }
  }

  string cmd;
  Interpreter interpret;
  Game g{startlvl, textOnly, script1, script2, seed};
  int turn = 1;

  try {
  while (true) {
    cin >> cmd;
    string comm;
    interpret.processCommands(cmd, &g, &turn);
  }
  }
  catch (ios::failure &) {}
}
