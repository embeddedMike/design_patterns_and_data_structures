#pragma once
#include "../inc/Automaton.h"
class Automaton;

class AutomatonState {
protected:
  Automaton *automaton_;

public:
  virtual ~AutomatonState() {}

  void setContext(Automaton *context) { this->automaton_ = context; }
  virtual bool Handle1(char trigger) = 0;
};