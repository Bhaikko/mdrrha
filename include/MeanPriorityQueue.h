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
    float sum;    

public:
    MeanPriorityQueue();

    void Push(Process *);
    Process *Top();
    void Pop();
    float GetMean();
    int GetQueueSize();
    bool Empty();
    void Execute(float t, int*, int*);

    ~MeanPriorityQueue();
};
