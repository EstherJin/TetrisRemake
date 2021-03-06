#include "i.h"
using namespace std;

I::I(): Block1{0, 'I'} {
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
  coords.emplace_back(Coordinates {3,3});
}

void I::turn(int shift){
  if (shift > 0){
    shift = shift % 4;
  } else{
    shift = ((-4 * shift) - (shift * -1)) % 4;
  }
  if ((shift % 2) != 0){
    if (position == 0){
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row -= 1;
      coords.at(1).col -= 1;
      stat = {c, coords.at(1), true};
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
      coords.at(3).row -= 3;
      coords.at(3).col -= 3;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 1;
    } else {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row += 1;
      coords.at(1).col += 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row += 2;
      coords.at(2).col += 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 3;
      coords.at(3).col += 3;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 0;
    }
  }
}

vector<Coordinates> I::turnPos(int shift){
  if (shift > 0){
    shift = shift % 4;
  } else{
    shift = ((-4 * shift) - (shift * -1)) % 4;
  }
  vector<Coordinates> cds = coords;
  if ((shift % 2) != 0){
    if (position == 0){
      cds.at(1).row -= 1;
      cds.at(1).col -= 1;
      cds.at(2).row -= 2;
      cds.at(2).col -= 2;
      cds.at(3).row -= 3;
      cds.at(3).col -= 3;
    } else {
      cds.at(1).row += 1;
      cds.at(1).col += 1;
      cds.at(2).row += 2;
      cds.at(2).col += 2;
      cds.at(3).row += 3;
      cds.at(3).col += 3;
    }
  }
  return cds;
}
