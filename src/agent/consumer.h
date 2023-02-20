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
#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "agent/shapeless_agent.h"

namespace bdm {

struct Product {
  std::string name;
  std::string category;
  real_t price;
};

class Consumer : public ShapelessAgent {
  BDM_AGENT_HEADER(Consumer, ShapelessAgent, 1);

 public:
  Consumer(real_t income = 0.0, const std::string& location = "",
           const std::vector<Product*>& interests = {})
      : income_(income), location_(location), interests_(interests) {}

  real_t income_;
  std::string location_;
  std::vector<Product*> interests_;
};

}  // namespace bdm

#endif  // CONSUMER_H_
