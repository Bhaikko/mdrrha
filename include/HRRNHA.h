#pragma once

#include <cmath>
#include <queue>
#include <unordered_map>

#include "./Algorithm.h"

class HRRNHA : public Algorithm
{
private:
    float quantum;

private:
    std::vector<Process*> readyQueue;
    std::vector<Process*> processesToPushAfterRound;
    std::vector<int> proccessToErase;

    std::unordered_map<int, int> tqs;

private:
    void SortReadyQueue();
    float GetMean();
    void FillTimeQuantums();
    void FillReadyQueueFromPending();

public:
    HRRNHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~HRRNHA();

};