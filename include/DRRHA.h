#pragma once

#include <queue>
#include "./Algorithm.h"

class DRRHA : public Algorithm
{
private:
    float quantum;

public:
    DRRHA(std::vector<Process> processesToExecute, float quantum);

    virtual void RunAlgo() override;

    ~DRRHA();
};