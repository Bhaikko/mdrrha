#pragma once

#include <cmath>
#include <queue>

#include "./../include/MeanPriorityQueue.h"
#include "./Algorithm.h"


class DRRHA : public Algorithm
{
private:
    float quantum;

private:
    std::vector<Process*> readyQueue;
    std::vector<Process*> processesToPushAfterRound;

private:
    void SortReadyQueue();
    float GetMean();
    std::vector<int> FillTimeQuantums();
    void FillReadyQueueFromPending();

public:
    DRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~DRRHA();

};