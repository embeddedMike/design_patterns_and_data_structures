#pragma once
#include "../ifc/AutomatonState.h"

class AutomatonThirdState : public AutomatonState {
public:
  bool Handle1(char trigger) override;
};