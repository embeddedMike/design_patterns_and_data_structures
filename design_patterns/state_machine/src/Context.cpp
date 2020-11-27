#include "../inc/Context.h"
#include <iostream>
#include <typeinfo>

void Context::changeState(State *state) {
  std::cout << "Context: Transition to " << typeid(*state).name() << std::endl;
  if (this->state_ != nullptr) {
    delete this->state_;
  }
  this->state_ = state;
  this->state_->set_context(this);
}
void Context::Request1() { this->state_->Handle1(); }

void Context::Request2() { this->state_->Handle2(); }