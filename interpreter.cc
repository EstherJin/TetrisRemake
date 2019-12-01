#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "interpreter.h"
#include "game.h"
using namespace std;

Interpreter::Interpreter(){
  commands["down"] = {"do","dow","down"};
  commands["left"] = {"lef","left"};
  commands["right"] = {"ri","rig","righ","right"};
  commands["clockwise"] = {"cl","clo","cloc","clock","clockw","clockwi","clockwis","clockwise"};
  commands["counterclockwise"] = {"co","cou","coun","count","counte","counter","counterc","countercl","counterclo","countercloc","counterclock","counterclockw","counterclockwi","counterclockwis","counterclockwise"};
  commands["drop"] = {"dr","dro","drop"};
  commands["levelup"] = {"levelu","levelup"};
  commands["leveldown"] = {"leveld","leveldo","leveldow","leveldown"};
  commands["norandom"] = {"n","no","nor","nora","noran","norand","norando","norandom"};
  commands["random"] = {"ra","ran","rand","rando","random"};
  commands["sequence"] = {"s","se","seq","sequ","seque","sequen","sequenc","sequence"};
  commands["restart"] = {"re","res","rest","resta","restar","restart"};
}

void Interpreter::processCommands(string cmd, Game *g, int *turn){
  string command = "";
  int n = 1;
  if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
    int i = 1;
    int n = cmd[0] - '0';
    while ((cmd[i] >= '0') && (cmd[i] <= '9')){
      n = n * 10 + (cmd[i] - '0');
      ++i;
    }
    cmd = cmd.substr(i);
  }
  map<string, vector<string>>::iterator it;
  for(it = commands.begin(); it != commands.end(); it++) {
    string key = it->first;
    vector<string> commands = it->second;
    int size = commands.size();
    for(int i = 0; i < size; ++i){
      if (cmd == commands.at(i)){
        command = key;
      }
    }
  }
  if (command != ""){
    if (command == "norandom"){
      string file;
      cin >> file;
      g->processCommand(command, file, n, *turn);
    } else if (command == "sequence"){
      string file;
      cin >> file;
      ifstream f{file};
      if (f){
        string comm;
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(f.rdbuf());
        while(f >> comm){
          processCommands(comm, g, turn);
        }
        cin.rdbuf(cinbuf);
      }
    } else if (command == "drop") {
      g->processCommand(command, n, *turn);
      *turn = (*turn % 2) + 1;
    } else if (command == "restart") {
      g->processCommand(command, n, *turn);
      *turn = 1;
    }else {
      g->processCommand(command, n, *turn);
    }
  }
}
