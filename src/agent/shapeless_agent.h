// -----------------------------------------------------------------------------
//
// Copyright (C) 2021 CERN & University of Surrey for the benefit of the
// BioDynaMo collaboration. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// See the LICENSE file distributed with this work for details.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership.
//
// -----------------------------------------------------------------------------
#ifndef SHAPELESS_AGENT_H_
#define SHAPELESS_AGENT_H_

#include "biodynamo.h"

namespace bdm {

class ShapelessAgent : public Agent {
  BDM_AGENT_HEADER(ShapelessAgent, Agent, 1);

 public:
  ShapelessAgent() {}

  // Overwrite abstract methods from Base class
  Shape GetShape() const override { return Shape::kSphere; }
  real_t GetDiameter() const override { return 0; }
  const Real3& GetPosition() const override {
    static Real3 kDefault{0, 0, 0};
    return kDefault;
  }
  void SetDiameter(real_t diameter) override {}
  void SetPosition(const Real3& position) override {}
  Real3 CalculateDisplacement(const InteractionForce* force,
                              real_t squared_radius, real_t dt) override {
    return {0, 0, 0};
  }
  void ApplyDisplacement(const Real3& displacement) override {}
  // Overwrite end
};

}  // namespace bdm

#endif  // SHAPELESS_AGENT_H_
