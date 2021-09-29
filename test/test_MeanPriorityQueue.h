#include <queue>

#include "./../include/Process.h"

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
    // minPQ queue;
    

public:
    MeanPriorityQueue();

    void Push(Process *);
    Process *Top();
    void Pop();
    void Execute(float t);
    float GetMean();
    int GetQueueSize();
    bool Empty();
    void PopWithoutSum();
    void Execute_extended(float t, int*, int*);
};
