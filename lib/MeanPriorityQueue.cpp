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

    // std::cout << "Popping: " << _queue[front]->p_id << " " << _queue[front]->burstTime << std::endl;
    sum -= _queue[front]->burstTime;
    front++;
    processesInQueue--;
}

float MeanPriorityQueue::GetMedian()
{
    return _queue[(front + _queue.size()) / 2]->burstTime;
}

float MeanPriorityQueue::GetMean()
{
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

MeanPriorityQueue::~MeanPriorityQueue() { }