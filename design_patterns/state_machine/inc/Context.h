#pragma once
#include "../ifc/State.h"

class Context {
private:
  State *state_;

public:
  Context(State *state) : state_(nullptr) { this->changeState(state); }

  ~Context() { delete state_; }

  void changeState(State *state);
  void Request1();
  void Request2();
};
