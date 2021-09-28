#pragma once

#include <queue>
#include "./Algorithm.h"

class DRRHA : public Algorithm
{
private:
    int quantum;

public:
    DRRHA(std::vector<Process> processesToExecute, int quantum);

    virtual void RunAlgo() override;

    ~DRRHA();
};