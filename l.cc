#include "l.h"
using namespace std;

L::L(): Block1{0, 'L'} {
  coords.emplace_back(Coordinates {2,2});
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
}

void L::turn(int shift){
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
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
      coords.at(3).col -= 2;
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row -= 1;
      coords.at(2).col += 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 1;
      coords.at(3).col += 1;
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
    } else if (position == 2) {
      State stat = {' ', coords.at(0), false};
      setState(stat);
      notifyObservers();
      coords.at(0).row -= 1;
      stat = {c, coords.at(0), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col += 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row -= 1;
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
    } else {
      State stat = {' ', coords.at(0), false};
      setState(stat);
      notifyObservers();
      coords.at(0).row += 1;
      coords.at(0).col += 2;
      stat = {c, coords.at(0), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col -= 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row += 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 1;
      coords.at(3).col += 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    }
    --shift;
    position = (position + 1) % 4;
  }
}

vector<Coordinates> L::turnPos(int shift){
  vector<Coordinates> cds = coords;
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
      coords.at(0).col -= 2;
      coords.at(3).row -= 2;
      coords.at(3).col -= 2;
    } else if (position == 1) {
      coords.at(2).row -= 1;
      coords.at(2).col += 1;
      coords.at(3).row += 1;
      coords.at(3).col += 1;
    } else if (position == 2) {
      coords.at(0).row -= 1;
      coords.at(1).col += 1;
      coords.at(2).row -= 1;
      coords.at(2).col -= 1;
    } else {
      coords.at(0).row += 1;
      coords.at(0).col += 2;
      coords.at(1).col -= 1;
      coords.at(2).row += 2;
      coords.at(3).row += 1;
      coords.at(3).col += 1;
    }
    --shift;
  }
  return cds;
}
