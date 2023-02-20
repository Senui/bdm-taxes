#ifndef SIM_PARAM_H_
#define SIM_PARAM_H_

#include <vector>

#include "biodynamo.h"

#include "model_facts.h"

namespace bdm {

/// This class defines parameters that are specific to this simulation.
class SimParam : public ParamGroup {
 private:
  BDM_CLASS_DEF_OVERRIDE(SimParam, 1);

 public:
  static const ParamGroupUid kUid;
  virtual ~SimParam() {}
  ParamGroup* NewCopy() const override { return new SimParam(*this); }
  ParamGroupUid GetUid() const override { return kUid; }

  // Amount of times to repeat the simulation (for statistical reasons)
  int repeat = 0;
  uint64_t num_consumers = 100;
};

}  // namespace bdm

#endif  // SIM_PARAM_H_
