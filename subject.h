#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "state.h"


class Observer;

class Subject {
  std::vector<Observer*> observers;
  State state;
 protected:
  void setState(newS);
 public:
  void attach(Observer *o);
  void notifyObservers();
  void detach(); //TODO: figure out this function
  State getState() const;
};
#endif
