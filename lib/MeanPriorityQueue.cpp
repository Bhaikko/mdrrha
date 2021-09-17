#include "./../include/MeanPriorityQueue.h"

MeanPriorityQueue::MeanPriorityQueue() 
{
    sum = 0;
}

void MeanPriorityQueue::AddProcess(Process& process)
{
    sum += process.burstTime;
    queue.push(&process);
}

Process* MeanPriorityQueue::Top()
{
    return queue.top();
}

void MeanPriorityQueue::Pop()
{
    if (queue.empty()) {
        return;
    }

    sum -= queue.top()->burstTime;
    queue.pop();
}

float MeanPriorityQueue::GetMean()
{
    return sum / (queue.size() * 1.0f);
}