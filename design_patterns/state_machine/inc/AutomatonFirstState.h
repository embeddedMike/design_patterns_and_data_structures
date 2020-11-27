#pragma once
#include "../ifc/AutomatonState.h"

class AutomatonFirstState : public AutomatonState {
public:
  bool Handle1(char trigger) override;
};