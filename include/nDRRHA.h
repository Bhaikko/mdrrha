#pragma once

#include <cmath>
#include <queue>

#include "./../include/MeanPriorityQueue.h"
#include "./Algorithm.h"


class nDRRHA : public Algorithm
{
private:
    float quantum;

public:
    nDRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~nDRRHA();
};