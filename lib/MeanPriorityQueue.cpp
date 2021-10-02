#include "./../include/MeanPriorityQueue.h"

MeanPriorityQueue::MeanPriorityQueue()
{
    sum = 0;
    front = 0;
    rear = 0;
    processesInQueue = 0;
}

void MeanPriorityQueue::Push(Process *p)
{
    sum += p->burstTime;
    _queue.push_back(p);
    rear++;
    processesInQueue++;

    queue.push(p);
}

Process *MeanPriorityQueue::Top()
{
    // return queue.top();
    return _queue[front];
}

void MeanPriorityQueue::Pop()
{
    // if (queue.empty())
    // {
    //     return;
    // }

    queue.pop();

    if (front > rear) {
        return;
    }

    std::cout << "Popping: " << _queue[front]->p_id << " " << _queue[front]->burstTime << std::endl;
    sum -= _queue[front]->burstTime;
    front++;
    processesInQueue--;
}


float MeanPriorityQueue::GetMean()
{
    // return queue.size() == 0 ? 0.0f : sum / (queue.size() * 1.0f);
    return _queue.size() == 0 ? 0.0f : sum / (processesInQueue * 1.0f);
}

int MeanPriorityQueue::GetQueueSize() { return processesInQueue; }

bool MeanPriorityQueue::Empty()
{
    return (processesInQueue == 0);
    // return(queue.empty());
}

void MeanPriorityQueue::SortQueue()
{
    std::sort(_queue.begin() + front, _queue.end(), [](Process* first, Process* second) -> bool {
        return first->burstTime < second->burstTime;
    });
}

void MeanPriorityQueue::Execute(float t, int *ct, int *nCS)
{
    // Process *p = queue.top();

    // if (queue.empty())
    // {
    //     return;
    // }

    // if (t >= p->burstTime)
    // {
    //     sum -= p->burstTime;
    //     *ct += p->burstTime;
    //     p->completionTime = *ct;
    //     p->burstTime = 0;
    //     this->Pop();
    //     // *nCS += 1;
    //     // p->burstTime = 0;
    // }
    // else
    // {
    //     sum -= t;
    //     *ct += t;
    //     p->burstTime -= t;
    //     if(p->burstTime <= t){
    //         *ct += p->burstTime;
    //         p->burstTime = 0;
    //         p->completionTime = *ct;
    //         this->Pop();
            
    //     }
    //     else{
    //         // p->burstTime -= t;
    //         Pop();
    //         Push(p);
    //     }

    // }
}

MeanPriorityQueue::~MeanPriorityQueue() { }