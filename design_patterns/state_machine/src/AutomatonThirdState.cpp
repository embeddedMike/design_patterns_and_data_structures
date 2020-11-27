#include "../inc/AutomatonThirdState.h"
#include "../inc/AutomatonSecondState.h"
#include <iostream>
bool AutomatonThirdState::Handle1(char trigger) {
  if (trigger == '0' or trigger == '1') {
    std::cout << "change state q3 -> q2" << std::endl;
    this->automaton_->changeState(new AutomatonSecondState);
    return true;
  }
}