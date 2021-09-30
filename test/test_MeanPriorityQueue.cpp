#include "./test_MeanPriorityQueue.h"

TestMeanPriorityQueue::TestMeanPriorityQueue()
{
    sum = 0;
}

void TestMeanPriorityQueue::Push(Process *p)
{
    sum += p->burstTime;
    queue.push(p);
}

Process *TestMeanPriorityQueue::Top()
{
    return queue.top();
}

void TestMeanPriorityQueue::Pop()
{
    if (queue.empty())
    {
        return;
    }

    queue.pop();
}


float TestMeanPriorityQueue::GetMean()
{
    return queue.size() == 0 ? 0.0f : sum / (queue.size() * 1.0f);
}

int TestMeanPriorityQueue::GetQueueSize() { return queue.size(); }

bool TestMeanPriorityQueue::Empty()
{
    return(queue.empty());
}


void TestMeanPriorityQueue::Execute(float t, int *ct, int *nCS)
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
        *nCS += 1;
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