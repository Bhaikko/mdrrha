#pragma once

#include <cmath>
#include <queue>

#include "./../include/MeanPriorityQueue.h"
#include "./Algorithm.h"


class DRRHA : public Algorithm
{
private:
    float quantum;

public:
    DRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~DRRHA();
};