#include "../inc/AutomatonSecondState.h"
#include "../inc/AutomatonThirdState.h"
#include <iostream>

bool AutomatonSecondState::Handle1(char trigger) {
  // std::cout << "nara" << std::endl;
  if (trigger == '0') {
    std::cout << "change state q2 -> q3" << std::endl;
    this->automaton_->changeState(new AutomatonThirdState);
    return false;
  }
  return true;
}