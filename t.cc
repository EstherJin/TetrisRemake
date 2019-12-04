#include "t.h"
using namespace std;

T::T(): Block1{0, 'T'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {2,2});
  coords.emplace_back(Coordinates {3,1});
}

void T::turn(int shift){
  if (shift > 0){
    shift = shift % 4;
  } else{
    shift = ((-4 * shift) - (shift * -1)) % 4;
  }
  while (shift > 0){
    if (position == 0){
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row -= 1;
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(0), false};
      setState(stat);
      notifyObservers();
      coords.at(0).row += 1;
      stat = {c, coords.at(0), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row += 2;
      coords.at(2).col += 1;
      stat = {c, coords.at(2), true};
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
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row -= 2;
      coords.at(2).col -= 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).col -= 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else {
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row += 1;
      coords.at(2).col += 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).col += 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    }
    position = (position + 1) % 4;
    --shift;
  }
}

vector<Coordinates> T::turnPos(int shift){
  vector<Coordinates> cds = coords;
  if (shift > 0){
    shift = shift % 4;
  } else{
    shift = ((-4 * shift) - (shift * -1)) % 4;
  }
  int pos = position;
  while (shift > 0){
    if (pos == 0){
      cds.at(2).row -= 1;
      cds.at(2).col -= 1;
    } else if (pos == 1) {
      cds.at(0).row += 1;
      cds.at(2).row += 2;
      cds.at(2).col += 1;
    } else if (pos == 2) {
      cds.at(0).row -= 1;
      cds.at(2).row -= 2;
      cds.at(2).col -= 2;
      cds.at(3).col -= 1;
    } else {
      cds.at(2).row += 1;
      cds.at(2).col += 2;
      cds.at(3).col += 1;
    }
    pos = (pos + 1) % 4;
    --shift;
  }
  return cds;
}
