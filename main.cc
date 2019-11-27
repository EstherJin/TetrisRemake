#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "game.h"
using namespace std;


int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Game g;
  int turn = 1;

  map<string, vector<string>> commands;
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

  try {
  while (true) {
    cin >> cmd;
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
    try{
      map<string, vector<string>>::iterator it;
      for(it = commands.begin(); it != commands.end(); it++) {
        string key = it->first;
        vector<string> command = it->second;
        int size = command.size();
        for(int i = 0; i < size; ++i){
          if (cmd == command.at(i)){
            throw key;
          }
        }
      }
    }
    catch(string comm){
      if ((comm == "sequence") || (comm == "norandom")){
        cin >> cmd;
        g.processCommand(comm, cmd, n, turn);
      } else if (comm == "drop") {
        g.processCommand(comm, n, turn);
        turn = (turn % 2) + 1;
      } else {
        g.processCommand(comm, n, turn);
      }
    }
  }
  }
  catch (ios::failure &) {}
}
