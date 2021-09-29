#include "./test_MeanPriorityQueue.h"

TestMeanPriorityQueue::TestMeanPriorityQueue()
{
    sum = 0;
}

void TestMeanPriorityQueue::Push(Process *p)
{
    sum += p->burstTime;
    // std::cout << sum << " ";
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

    sum -= queue.top()->burstTime;
    // std::cout << sum << " ";

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

void TestMeanPriorityQueue::PopWithoutSum() 
{
    if (queue.empty())
    {
        return;
    }

    // sum -= queue.top()->burstTime;

    queue.pop();
}

void TestMeanPriorityQueue::Execute_extended(float t, int *ct, int *nCS)
{
    Process *p = queue.top();

    if (queue.empty())
    {
        return;
    }

    // std::cout << t << std::endl;

    if (t >= p->burstTime)
    {
        sum -= p->burstTime;
        *ct += p->burstTime;
        p->completionTime = *ct;
        p->burstTime = 0;
        // this->Pop();
        PopWithoutSum();
        *nCS += 1;
        // p->burstTime = 0;
        // std::cout << sum << " ";
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
            // this->Pop();
            PopWithoutSum();
            
            // p->burstTime = 0;
            // p->completionTime = *ct;
        }
        else{
            // p->burstTime -= t;
            // Pop();
            PopWithoutSum();
            Push(p);
        }

        // std::cout << sum << " ";
    }
    
    // p->burstTime -= t;
    // if (p->burstTime < 0)
    // {
    //     p->burstTime = 0;
    //     p->completionTime = *ct;
    //     this->Pop();
    // }
}