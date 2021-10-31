#pragma once

#include <cmath>
#include <queue>

#include "./../include/MeanPriorityQueue.h"
#include "./Algorithm.h"


class mDRRHA : public Algorithm
{
private:
    float quantum;

public:
    mDRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~mDRRHA();
};