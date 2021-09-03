#pragma once

#include "./Algorithm.h"

class RoundRobin : public Algorithm
{
public:
    RoundRobin(std::vector<Process>* processesToExecute);

    virtual void RunAlgo() override;

    ~RoundRobin();
};