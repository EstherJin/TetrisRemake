#ifndef BLOCK1_H
#define BLOCK1_H
#include <vector>
#include "coords.h"
#include "subject.h"
using namespace std;

class Block1{
protected:
  vector<Coordinates> coords;
  int position;
  char c;
public:
  Block1(int position, char c);
  virtual ~Block1();
  virtual void move(int shift);
  virtual void turn(int shift)=0;
  void down(int shift);
  virtual vector<Coordinates> movePos(int shift);
  virtual vector<Coordinates> turnPos(int shift)=0;
  vector<Coordinates> downPos(int shift);
  char getType();
  void print(){
    for(int i = 0; i < 4; ++i){
      cout << "[";
      cout << coords.at(i).row;
      cout << ",";
      cout << coords.at(i).col;
      cout << "],";
    }
    cout << endl;
  }
};

Block1::Block1(int position, char c): position{position}, c{c}{}

Block1::~Block1(){}

char Block1::getType(){
  return c;
}

void Block1::move(int shift){
  for (int i = 0; i < 4; ++i){
    State stat = {' ', coords, false};
    setState(stat);
    notifyObservers();
    coords.at(i).col += shift;
    stat = {c, coords, true};
    setState(stat);
    notifyObservers();
  }
}
vector<Coordinates> Block1::movePos(int shift){
  vector<Coordinates> cds = coords;
  for (int i = 0; i < 4; ++i){
    cds.at(i).col += shift;
  }
  return cds;
}

void Block1::down(int shift){
  int size = coords.size();
  for (int i = 0; i < size; ++i){
    State stat = {' ', coords, false};
    setState(stat);
    notifyObservers();
    coords.at(i).row += shift;
    stat = {c, coords, true};
    setState(stat);
    notifyObservers();
  }
}

vector<Coordinates> Block1::downPos(int shift){
  vector<Coordinates> cds = coords;
  int size = coords.size();
  for (int i = 0; i < size; ++i){
    cds.at(i).row += shift;
  }
  return cds;
}

class O: public Block1 {
public:
  O();
  ~O(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

O::O(): Block1{0, 'O'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
}

void O::turn(int shift){}

vector<Coordinates> O::turnPos(int shift){
  return coords;
}

class S: public Block1 {
public:
  S();
  ~S(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

S::S(): Block1{0, 'S'} {
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {2,2});
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
}

void S::turn(int shift){
  if ((shift % 2) != 0){
    if (position == 0){
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col -= 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 1;
    } else {
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col += 2;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      position = 0;
    }
  }
}

vector<Coordinates> S::turnPos(int shift){
  vector<Coordinates> cds = coords;
  if ((shift % 2) != 0){
    if (position == 0){
      cds.at(2).col -= 2;
      cds.at(3).row -= 2;
    } else {
      cds.at(2).col += 2;
      cds.at(3).row += 2;
    }
  }
  return cds;
}

class Z: public Block1 {
public:
  Z();
  ~Z(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

Z::Z(): Block1{0, 'Z'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
}

void Z::turn(int shift){
  if ((shift % 2) != 0){
    if (position == 0){
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col += 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 2;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
      position = 1;
    } else {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col -= 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row -= 2;
      stat = {c, coords.at(4), true};
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
      cds.at(1).col += 2;
      cds.at(4).row += 2;
    } else {
      cds.at(1).col -= 2;
      cds.at(4).row -= 2;
    }
  }
  return cds;
}

class I: public Block1 {
public:
  I();
  ~I(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

I::I(): Block1{0, 'I'} {
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
  coords.emplace_back(Coordinates {3,3});
}

void I::turn(int shift){
  if ((shift % 2) != 0){
    if (position == 0){
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row -= 1;
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col -= 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      State stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row -= 1;
      coords.at(4).col -= 3;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
      position = 1;
    } else {
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).row += 1;
      coords.at(2).col += 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 1;
      coords.at(3).col += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      State stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 3;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
      position = 0;
    }
  }
}

vector<Coordinates> I::turnPos(int shift){
  vector<Coordinates> cds = coords;
  if ((shift % 2) != 0){
    if (position == 0){
      cds.at(2).row -= 1;
      cds.at(2).col -= 1;
      cds.at(3).row -= 1;
      cds.at(3).col -= 2;
      cds.at(4).row -= 1;
      cds.at(4).col -= 3;
    } else {
      cds.at(2).row += 1;
      cds.at(2).col += 1;
      cds.at(3).row += 1;
      cds.at(3).col += 2;
      cds.at(4).row += 1;
      cds.at(4).col += 3;
    }
  }
  return cds;
}

class J: public Block1 {
public:
  J();
  ~J(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

J::J(): Block1{0, 'J'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {3,0});
  coords.emplace_back(Coordinates {3,1});
  coords.emplace_back(Coordinates {3,2});
}

void J::turn(int shift){
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row -= 2;
      coords.at(4).col -= 2;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col += 2;
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
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    } else if (position == 2) {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row += 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col -= 1;
      tat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row -= 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    }
    position = (position + 1) % 4;
    --shift;
  }
}

vector<Coordinates> J::turnPos(int shift){
  vector<Coordinates> cds = coords;
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
      cds.at(3).row -= 2;
      cds.at(4).row -= 2;
      cds.at(4).col -= 2;
    } else if (position == 1) {
      cds.at(2).col += 2;
      cds.at(3).row += 1;
      cds.at(3).col += 1;
      cds.at(4).row += 1;
      cds.at(4).col += 1;
    } else if (position == 2) {
      cds.at(1).row += 1;
      cds.at(2).col -= 1;
      cds.at(3).row -= 1;
      cds.at(3).col -= 1;
    } else {
      cds.at(1).row -= 1;
      cds.at(2).col -= 1;
      cds.at(3).row += 2;
      cds.at(4).row += 1;
      cds.at(4).col += 1;
    }
    --shift;
  }
  return cds;
}

class L: public Block1 {
public:
  L();
  ~L(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

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
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col -= 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row -= 2;
      coords.at(4).col -= 2;
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col += 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
    } else if (position == 2) {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row -= 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col += 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col -= 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else {}
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row += 1;
      coords.at(1).col += 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
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
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).col -= 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row -= 2;
      coords.at(4).col -= 2;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col += 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    } else if (position == 2) {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row -= 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col += 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col -= 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row += 1;
      coords.at(1).col += 2;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(2), false};
      setState(stat);
      notifyObservers();
      coords.at(2).col -= 1;
      stat = {c, coords.at(2), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).row += 1;
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    }
    --shift;
  }
  return cds;
}

class T: public Block1 {
public:
  T();
  ~T(){}
  void turn(int shift) override;
  vector<Coordinates> turnPos(int shift) override;
};

T::T(): Block1{0, 'T'} {
  coords.emplace_back(Coordinates {2,0});
  coords.emplace_back(Coordinates {2,1});
  coords.emplace_back(Coordinates {2,2});
  coords.emplace_back(Coordinates {3,1});
}

void T::turn(int shift){
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 1;
      coords.at(3).col -= 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else if (position == 1) {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row += 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 2;
      coords.at(3).col += 1;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
    } else if (position == 2) {
      State stat = {' ', coords.at(1), false};
      setState(stat);
      notifyObservers();
      coords.at(1).row -= 1;
      stat = {c, coords.at(1), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row -= 2;
      coords.at(3).col -= 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).col -= 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    } else {
      State stat = {' ', coords.at(3), false};
      setState(stat);
      notifyObservers();
      coords.at(3).row += 1;
      coords.at(3).col += 2;
      stat = {c, coords.at(3), true};
      setState(stat);
      notifyObservers();
      stat = {' ', coords.at(4), false};
      setState(stat);
      notifyObservers();
      coords.at(4).col += 1;
      stat = {c, coords.at(4), true};
      setState(stat);
      notifyObservers();
    }
    position = (position + 1) % 4;
    --shift;
  }
}

vector<Coordinates> T::turnPos(int shift){
  vector<Coordinates> cds = coords;
  shift = shift % 4;
  while (shift > 0){
    if (position == 0){
      coords.at(3).row -= 1;
      coords.at(3).col -= 1;
    } else if (position == 1) {
      coords.at(1).row += 1;
      coords.at(3).row += 2;
      coords.at(3).col += 1;
    } else if (position == 2) {
      coords.at(1).row -= 1;
      coords.at(3).row -= 2;
      coords.at(3).col -= 2;
      coords.at(4).col -= 1;
    } else {
      coords.at(3).row += 1;
      coords.at(3).col += 2;
      coords.at(4).col += 1;
    }
    --shift;
  }
  return cds;
}

class Dot: public Block1 {
public:
  Dot();
  ~Dot(){}
  void move(int shift);
  void turn(int shift);
  vector<Coordinates> movePos(int shift);
  vector<Coordinates> turnPos(int shift);
};

Dot::Dot(): Block1{0, '*'} {
  coords.emplace_back(Coordinates {3,5});
}

void move(int shift){}

vector<Coordinates> movePos(int shift){
  return coords;
}

void turn(int shift){}

vector<Coordinates> turnPos(int shift){
  return coords;
}

#endif
