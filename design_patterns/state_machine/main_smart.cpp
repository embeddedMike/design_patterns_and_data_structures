#include <iostream>
#include <vector>
#include <memory>

class Context;

class State {
 protected:
  Context *context_;

public:
  virtual ~State() {}

  void set_context(Context *context) { this->context_ = context; }
  virtual void Handle1() = 0;
  virtual void Handle2() = 0;
};

class Context {
private:
  std::unique_ptr<State> state_;

public:
  Context(std::unique_ptr<State> state) : state_(nullptr) { this->changeState(std::move(state)); }

  ~Context() { //delete state_; 
  }

  void changeState(std::unique_ptr<State> state) {
    std::cout << "Context: Transition to " << typeid(*state).name()
              << std::endl;
    if (this->state_ != nullptr) {
      //delete this->state_;
    }
    this->state_ = std::move(state);
    this->state_->set_context(this);
  }
  void Request1() { this->state_->Handle1(); }
  void Request2() { this->state_->Handle2(); }
};

class ConcreteStateA : public State {
public:
  void Handle1() override;
  void Handle2() override { std::cout << "ConcreteStateA handles request2.\n"; }
};

class ConcreteStateB : public State {
public:
  void Handle1() override { std::cout << "ConcreteStateB handles request1.\n"; }
  void Handle2() override {
    std::cout << "ConcreteStateB handles request2.\n";
    std::cout << "ConcreteStateB wants to change the state of the context.\n";
    this->context_->changeState(std::make_unique<ConcreteStateA>());
  }
};

void ConcreteStateA::Handle1() {
  std::cout << "ConcreteStateA handles request1.\n";
  std::cout << "ConcreteStateA want to change the state of the context.\n";
  this->context_->changeState(std::make_unique<ConcreteStateB>());
}

void ClientCode() {
  Context *context = new Context(std::make_unique<ConcreteStateA>());
  context->Request1();
  context->Request2();
  delete context;
}


class Automaton
{
public:
  Automaton();
  bool read_commands(const std::vector<char>& commands);
};



int main() {
  ClientCode();
  return 0;
}