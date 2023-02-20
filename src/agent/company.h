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
#ifndef COMPANY_H_
#define COMPANY_H_

#include "agent/shapeless_agent.h"

namespace bdm {

class Company : public ShapelessAgent {
  BDM_AGENT_HEADER(Company, ShapelessAgent, 1);

 public:
  Company(real_t income = 0.0, const std::string& name = "",
          const std::string& location = "")
      : income_(income), name_(name), location_(location) {}

  real_t income_;
  std::string name_;
  std::string location_;
};

}  // namespace bdm

#endif  // COMPANY_H_
