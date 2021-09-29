#include "./test_MeanPriorityQueue.h"

MeanPriorityQueue::MeanPriorityQueue()
{
    sum = 0;
}

void MeanPriorityQueue::Push(Process *p)
{
    sum += p->burstTime;
    // std::cout << sum << " ";
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

    sum -= queue.top()->burstTime;
    // std::cout << sum << " ";

    queue.pop();
}
void MeanPriorityQueue::Execute(float t)
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

bool MeanPriorityQueue::Empty()
{
    return(queue.empty());
}

void MeanPriorityQueue::PopWithoutSum() 
{
    if (queue.empty())
    {
        return;
    }

    // sum -= queue.top()->burstTime;

    queue.pop();
}

void MeanPriorityQueue::Execute_extended(float t, int *ct, int *nCS)
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
        this->Pop();
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
            this->Pop();
            
            // p->burstTime = 0;
            // p->completionTime = *ct;
        }
        else{
            // p->burstTime -= t;
            Pop();
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