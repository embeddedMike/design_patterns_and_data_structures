#pragma once
#include "../ifc/AutomatonState.h"
#include <vector>
class AutomatonState;
class Automaton {
private:
  AutomatonState *state_ = nullptr;

public:
  Automaton();
  // Automaton(){
  //  this->state_ = new AutomatonStateQ1;
  //};
  ~Automaton() { // delete state_;
  }
  bool read_commands(const std::vector<char> &commands);
  void changeState(AutomatonState *state);
};