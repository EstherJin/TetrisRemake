#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "state.h"

//I'm removing the template as we only have one state. We may need to readd infotype, not sure

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
  //virtual InfoType getInfo() const = 0; don't think we need this?
  State getState() const;
};

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

oid Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::setState(State newS) { state = newS; }

State Subject::getState() const { return state; }
#endif
