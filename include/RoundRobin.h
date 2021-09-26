#pragma once

#include "./Algorithm.h"

#define INFINITY 99999999

class RoundRobin : public Algorithm
{
private:
    int quantum;
    
public:
    RoundRobin(std::vector<Process> processesToExecute, int quantum);

    virtual void RunAlgo() override;

    ~RoundRobin();
};