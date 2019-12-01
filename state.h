#ifndef STATE_H
#define STATE_H
#include "coordinates.h"

struct State {
  char type;
  Coordinates coords;
  bool add;
};

#endif
