#include "z.h"
using namespace std;

Z::Z(): Block1{0, 'Z'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
}

void Z::turn(int shift){
  if ((shift % 2) != 0){
    if (position == 0){
      State stat = {' ', coords.at(0), false};
      setState(stat);
      notifyObservers();
      coords.at(0).col += 2;
      stat = {c, coords.at(0), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 1;
    } else {
      State stat = {' ', coords.at(0), false};
      setState(stat);
      notifyObservers();
      coords.at(0).col -= 2;
      stat = {c, coords.at(0), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 0;
    }
  }
}

vector<Coordinates> Z::turnPos(int shift){
  vector<Coordinates> cds = coords;
  if ((shift % 2) != 0){
    if (position == 0){
      cds.at(0).col += 2;
      cds.at(3).row += 2;
    } else {
      cds.at(0).col -= 2;
      cds.at(3).row -= 2;
    }
  }
  return cds;
}
