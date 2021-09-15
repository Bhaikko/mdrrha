#pragma once

#include <queue>
#include "./Algorithm.h"

struct CompareProcess
{
    bool operator()(const Process *lhs, const Process *rhs) const
    {
        return lhs->burstTime > rhs->burstTime;
    }
};

class SJF : public Algorithm
{

public:
    SJF(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~SJF();
};