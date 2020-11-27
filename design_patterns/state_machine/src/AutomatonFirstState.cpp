#include "../inc/AutomatonFirstState.h"
#include "../inc/AutomatonSecondState.h"
#include <iostream>
bool AutomatonFirstState::Handle1(char trigger) {
  if (trigger == '1') {
    std::cout << "change state q1 -> q2" << std::endl;
    this->automaton_->changeState(new AutomatonSecondState);
    return true;
  }
  return false;
}