#pragma once

#include <queue>
#include "./Algorithm.h"

class SJF : public Algorithm
{

public:
    SJF(std::vector<Process> *processesToExecute, int quantum);

    virtual void RunAlgo() override;

    ~SJF();
};