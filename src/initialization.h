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
#ifndef INITIALIZATION_H_
#define INITIALIZATION_H_

#include "biodynamo.h"

#include "agent/company.h"
#include "csv_helper.h"
#include "model_facts.h"
#include "sim_param.h"

namespace bdm {

inline void InitializeAgents() {
  // Initialize Companies
  std::vector<real_t> incomes;
  std::vector<std::string> names, locations;
  auto inputfile = Concat(GetDataDir(), "/company_incomes.csv");
  CsvToVector(inputfile, &incomes, "company_income", 0);
  CsvToVector(inputfile, &names, "company_name", 0);
  CsvToVector(inputfile, &locations, "headquarters_location", 0);

  auto* sim = Simulation::GetActive();
  auto* ctxt = sim->GetExecutionContext();
  for (size_t i = 0; i < incomes.size(); i++) {
    auto* new_company = new Company(incomes[i], names[i], locations[i]);
    ctxt->AddAgent(new_company);
  }

  // Initialize Consumers
  auto* sparam = Simulation::GetActive()->GetParam()->Get<SimParam>();
  for (size_t i = 0; i < sparam->num_consumers; i++) {
    auto* new_consumer = new Consumer();
    ctxt->AddAgent(new_consumer);
  }

  // Adds agents to ResourceManager
  sim->GetScheduler()->FinalizeInitialization();
}

}  // namespace bdm

#endif  // INITIALIZATION_H_