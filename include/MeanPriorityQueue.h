#include <queue>

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

    // minPQ queue;
    float sum;

public:
    MeanPriorityQueue();

    void Push(Process &process);
    Process *Top();
    void Pop();
    void Execute(float t);
    float GetMean();
    int GetQueueSize();
};