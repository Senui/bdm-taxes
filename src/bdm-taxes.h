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
#ifndef BDM_TAXES_H_
#define BDM_TAXES_H_

#include "biodynamo.h"

#include "agent/company.h"
#include "agent/consumer.h"
#include "initialization.h"
#include "sim_param.h"

namespace bdm {

inline int Simulate(int argc, const char** argv) {
  Param::RegisterParamGroup(new SimParam());
  Simulation simulation(argc, argv);

  InitializeAgents();

  auto* rm = simulation.GetResourceManager();
  std::cout << "Number of agents = " << rm->GetNumAgents() << std::endl;

  rm->ForEachAgent([&](Agent* a) {  // NOLINT
    if (auto* company = dynamic_cast<Company*>(a)) {
      std::cout << " > " << company->name_ << ", ";
      std::cout << company->income_ << ", ";
      std::cout << company->location_ << std::endl;
    }
  });

  std::cout << "Simulation completed successfully!" << std::endl;
  return 0;
}

}  // namespace bdm

#endif  // BDM_TAXES_H_
