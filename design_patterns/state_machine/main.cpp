#include <iostream>
#include <memory>
#include <vector>
////////////////////////EXAMPLE////////////////////////////////

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
  State *state_;

public:
  Context(State *state) : state_(nullptr) { this->changeState(state); }

  ~Context() { delete state_; }

  void changeState(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name()
              << std::endl;
    if (this->state_ != nullptr) {
      delete this->state_;
    }
    this->state_ = state;
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
    this->context_->changeState(new ConcreteStateA);
  }
};

void ConcreteStateA::Handle1() {
  std::cout << "ConcreteStateA handles request1.\n";
  std::cout << "ConcreteStateA want to change the state of the context.\n";
  this->context_->changeState(new ConcreteStateB);
}

void ClientCode() {
  Context *context = new Context(new ConcreteStateA);
  context->Request1();
  context->Request2();
  delete context;
}

////////////////////////AUTOMATON////////////////////////////////

class Automaton;

class AutomatonState {
protected:
  Automaton *automaton_;

public:
  virtual ~AutomatonState() {}

  void setContext(Automaton *context) { this->automaton_ = context; }
  virtual bool Handle1(char trigger) = 0;
};
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
  bool read_commands(const std::vector<char> &commands) {
    bool isAcceptedState = 0;
    for (const auto &command : commands) {
      isAcceptedState = this->state_->Handle1(command);
    }
    return isAcceptedState;
  }
  void changeState(AutomatonState *state) {
    if (state_ != nullptr) {
      delete state_;
    }
    this->state_ = state;
    this->state_->setContext(this);
  }
};

class AutomatonStateQ3 : public AutomatonState {

  bool Handle1(char trigger) override;
};

class AutomatonStateQ2 : public AutomatonState {

  bool Handle1(char trigger) override {
    // std::cout << "nara" << std::endl;
    if (trigger == '0') {
      std::cout << "change state q2 -> q3" << std::endl;
      this->automaton_->changeState(new AutomatonStateQ3);
      return false;
    }
    return true;
  }
};

bool AutomatonStateQ3::Handle1(char trigger) {
  if (trigger == '0' or trigger == '1') {
    std::cout << "change state q3 -> q2" << std::endl;
    this->automaton_->changeState(new AutomatonStateQ2);
    return true;
  }
}

class AutomatonStateQ1 : public AutomatonState {
  bool Handle1(char trigger) override {
    if (trigger == '1') {
      std::cout << "change state q1 -> q2" << std::endl;
      this->automaton_->changeState(new AutomatonStateQ2);
      return true;
    }
    return false;
  }
};

Automaton::Automaton() { // this->state_ = new AutomatonStateQ1;
  this->changeState(new AutomatonStateQ1);
};

////////////////////////TCP////////////////////////////////

int main() {
  // ClientCode();
  const std::vector<char> test{'1'};
  const std::vector<char> test2{'1', '0', '0', '1'};
  // std::unique_ptr<Automaton> automaton_ = new Automaton();
  std::unique_ptr<Automaton> automaton_ = std::make_unique<Automaton>();
  bool result = automaton_->read_commands(test2);
  std::cout << result;
  // delete automaton_;
  return 0;
}