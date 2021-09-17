#include <queue>

#include "./Process.h"

struct MinPriorityQueueCompare
{
    bool operator()(const Process* lhs, const Process* rhs) const
    {
        return lhs->burstTime > rhs->burstTime;
    }
};

class MeanPriorityQueue {
private:
    typedef std::priority_queue<Process*, std::vector<Process* >, MinPriorityQueueCompare> minPQ;
    
    minPQ queue;
    int sum;

public:
    MeanPriorityQueue();
    
    void Push(Process& process); 
    Process* Top();
    void Pop();
    float GetMean();
    int GetQueueSize();

};