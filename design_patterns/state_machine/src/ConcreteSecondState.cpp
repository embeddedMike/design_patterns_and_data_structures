#include "../inc/ConcreteSecondState.h"
#include "../inc/ConcreteFirstState.h"
#include <iostream>

void ConcreteSecondState::Handle1() {
  std::cout << "ConcreteStateB handles request1.\n";
}
void ConcreteSecondState::Handle2() {
  std::cout << "ConcreteStateB handles request2.\n";
  std::cout << "ConcreteStateB wants to change the state of the context.\n";
  this->context_->changeState(new ConcreteFirstState);
}