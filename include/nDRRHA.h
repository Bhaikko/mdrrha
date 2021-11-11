#pragma once

#include <cmath>
#include <queue>
#include <random>
#include <unordered_map>

#include "./Algorithm.h"


class NDRRHA : public Algorithm
{
private:
    float quantum;

private:
    int mean, standardDeviation;

    std::vector<Process*> readyQueue;
    std::vector<Process*> processesToPushAfterRound;
    std::vector<int> processesToErase;

    std::unordered_map<int, int> tqs;



private:
    void SortReadyQueue();
    void CalculateMeanAndSD();
    float GetMean();
    float GetNormalDistribution();
    void FillTimeQuantums();
    void FillReadyQueueFromPending();

public:
    NDRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    ~NDRRHA();
};