#pragma once
#include "../ifc/AutomatonState.h"

class AutomatonSecondState : public AutomatonState {
public:
  bool Handle1(char trigger) override;
};