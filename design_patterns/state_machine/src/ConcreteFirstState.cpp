#include "../inc/ConcreteFirstState.h"
#include "../inc/ConcreteSecondState.h"
#include <iostream>

void ConcreteFirstState::Handle1() {
  std::cout << "ConcreteStateA handles request1.\n";
  std::cout << "ConcreteStateA want to change the state of the context.\n";
  this->context_->changeState(new ConcreteSecondState);
}

void ConcreteFirstState::Handle2() {
  std::cout << "ConcreteStateA handles request2.\n";
}