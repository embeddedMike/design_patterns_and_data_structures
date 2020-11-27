#pragma once
#include "../ifc/State.h"

class ConcreteFirstState : public State {
public:
  void Handle1() override;
  void Handle2() override;
};