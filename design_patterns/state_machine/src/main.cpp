#include "../inc/Automaton.h"
#include <iostream>
#include <memory>
int main() {

  const std::vector<char> test{'1'};
  const std::vector<char> test2{'1', '0', '0', '1'};
  // std::unique_ptr<Automaton> automaton_ = new Automaton();
  std::unique_ptr<Automaton> automaton_ = std::make_unique<Automaton>();
  bool result = automaton_->read_commands(test2);
  std::cout << result << std::endl;
  std::cout << "test" << std::endl;
  return 0;
}