#include "../inc/Automaton.h"
#include "../inc/AutomatonFirstState.h"

Automaton::Automaton() { // this->state_ = new AutomatonStateQ1;
  this->changeState(new AutomatonFirstState);
}

bool Automaton::read_commands(const std::vector<char> &commands) {
  bool isAcceptedState = 0;
  for (const auto &command : commands) {
    isAcceptedState = this->state_->Handle1(command);
  }
  return isAcceptedState;
}

void Automaton::changeState(AutomatonState *state) {
  if (state_ != nullptr) {
    delete state_;
  }
  this->state_ = state;
  this->state_->setContext(this);
}