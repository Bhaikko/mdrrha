#include "./../include/MeanPriorityQueue.h"

MeanPriorityQueue::MeanPriorityQueue()
{
    sum = 0;
}

void MeanPriorityQueue::Push(Process *p)
{
    sum += p->burstTime;
    queue.push(p);
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

    queue.pop();
}


float MeanPriorityQueue::GetMean()
{
    return queue.size() == 0 ? 0.0f : sum / (queue.size() * 1.0f);
}

int MeanPriorityQueue::GetQueueSize() { return queue.size(); }

bool MeanPriorityQueue::Empty()
{
    return(queue.empty());
}


void MeanPriorityQueue::Execute(float t, int *ct, int *nCS)
{
    Process *p = queue.top();

    if (queue.empty())
    {
        return;
    }

    if (t >= p->burstTime)
    {
        sum -= p->burstTime;
        *ct += p->burstTime;
        p->completionTime = *ct;
        p->burstTime = 0;
        this->Pop();
        // *nCS += 1;
        // p->burstTime = 0;
    }
    else
    {
        sum -= t;
        *ct += t;
        p->burstTime -= t;
        if(p->burstTime <= t){
            *ct += p->burstTime;
            p->burstTime = 0;
            p->completionTime = *ct;
            this->Pop();
            
        }
        else{
            // p->burstTime -= t;
            Pop();
            Push(p);
        }

    }
}

MeanPriorityQueue::~MeanPriorityQueue() { }