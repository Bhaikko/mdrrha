#include "./../include/MeanPriorityQueue.h"

MeanPriorityQueue::MeanPriorityQueue()
{
    sum = 0;
}

void MeanPriorityQueue::Push(Process &process)
{
    sum += process.burstTime;
    // std::cout << sum << " ";
    queue.push(&process);
}

Process *MeanPriorityQueue::Top()
{
    return queue.top();
}

void MeanPriorityQueue::Pop()
{
    if (queue.empty())
    {
        return;
    }

    // sum -= queue.top()->burstTime;
    // std::cout << sum << " ";

    queue.pop();
}
void MeanPriorityQueue::Execute(int t)
{
    if (queue.empty())
    {
        return;
    }

    if (t > queue.top()->burstTime)
    {
        sum -= queue.top()->burstTime;
        // std::cout << sum << " ";
    }
    else
    {
        sum -= t;
        // std::cout << sum << " ";
    }
    queue.top()->burstTime -= t;
    if (queue.top()->burstTime < 0)
    {
        queue.top()->burstTime = 0;
    }
}

float MeanPriorityQueue::GetMean()
{
    return queue.size() == 0 ? 0.0f : sum / (queue.size() * 1.0f);
}

int MeanPriorityQueue::GetQueueSize() { return queue.size(); }