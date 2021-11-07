#pragma once

#include <cmath>
#include <queue>
#include <unordered_map>

#include "./../include/MeanPriorityQueue.h"
#include "./Algorithm.h"

class MDRRHA : public Algorithm
{
private:
    float quantum;

private:
    std::vector<Process*> readyQueue;
    std::vector<Process*> processesToPushAfterRound;
    std::vector<int> processesToErase;

    std::unordered_map<int, int> tqs;

private:
    void SortReadyQueue();
    int GetMedian();
    void FillTimeQuantums();
    void FillReadyQueueFromPending();

public:
    MDRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~MDRRHA();
};