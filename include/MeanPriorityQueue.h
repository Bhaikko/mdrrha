#pragma once

#include <queue>
#include <vector>
#include <algorithm>

#include "./Process.h"

struct MinPriorityQueueCompare
{
    bool operator()(const Process *lhs, const Process *rhs) const
    {
        return lhs->burstTime > rhs->burstTime;
    }
};

class MeanPriorityQueue
{
private:
    std::priority_queue<Process *, std::vector<Process *>, MinPriorityQueueCompare> queue;
    
    float sum;    
    std::vector<Process* > _queue;

    int front, rear;
    int processesInQueue;

public:
    MeanPriorityQueue();

    void Push(Process *);
    Process *Top();
    void Pop();
    int GetQueueSize();
    bool Empty();
    void SortQueue();

    ~MeanPriorityQueue();

public:
    float GetMean();
    float GetMedian();
    float GetNormalDistribution();
};
