#include <cmath>

#include "./../include/DRRHA.h"
#include "./../include/MeanPriorityQueue.h"

DRRHA::DRRHA(std::vector<Process> processesToExecute, int quantum) : Algorithm(processesToExecute)
{
    this->name = "DRRHA";
    this->quantum = quantum;
}

void DRRHA::RunAlgo()
{
    Algorithm::RunAlgo();

    // std::priority_queue<Process *, std::vector<Process *>, CompareProcess> ready_q;
    MeanPriorityQueue ready_q;
    int t = 0; // current time
    t = processesToExecute.at(0).arrivalTime;
    for (unsigned int i = 0; i < processesToExecute.size(); i++)
    {
        if (processesToExecute.at(i).arrivalTime <= t)
        {
            ready_q.Push(processesToExecute.at(i));
            // std::cout << i;
            continue;
        }
        else
        {
            i--;
        }
        quantum = ceil((ready_q.GetMean() / 2) + ((ready_q.GetMean() / 2) / (ready_q.Top()->burstTime)));
        // std::cout << "Top " << ready_q.Top()->burstTime << " ";
        // std::cout << "Q" << quantum << " " << ready_q.GetMean() << " " << ready_q.Top()->burstTime;
        // Process *temp = ready_q.Top();
        if (ready_q.Top()->burstTime <= quantum)
        {
            t += ready_q.Top()->burstTime;
        }
        else
        {
            t += quantum;
        }
        ready_q.Execute(quantum);
        nCS++;

        if (ready_q.Top()->burstTime > 0 && ready_q.Top()->burstTime <= quantum)
        {
            // ready_q.Execute(quantum);
            t += ready_q.Top()->burstTime; //**********************************
            nCS++;
            ready_q.Top()->completionTime = t;
            // std::cout << "U" << ready_q.Top()->completionTime << " ";
            // std::cout << ready_q.Top()->burstTime;
            ready_q.Pop();
        }
        else if (ready_q.Top()->burstTime <= 0)
        {
            // std::cout << "here ";
            ready_q.Top()->completionTime = t;
            // std::cout << "D" << ready_q.Top()->completionTime << " ";
            ready_q.Pop();
        }
        else
        {
            std::cout << "here";
        }
    }
    while (ready_q.GetQueueSize() > 0)
    {
        quantum = (ready_q.GetMean() / 2) + ((ready_q.GetMean() / 2) / (ready_q.Top()->burstTime));
        // std::cout << "Q" << quantum << " " << ready_q.GetMean() << " " << ready_q.Top()->burstTime;
        // Process *temp = ready_q.Top();
        ready_q.Execute(quantum);
        nCS++;
        t += quantum;
        if (ready_q.Top()->burstTime > 0 && ready_q.Top()->burstTime <= quantum)
        {
            ready_q.Execute(quantum);
            nCS++;
            t += quantum;
            ready_q.Top()->completionTime = t;
            // std::cout << "U" << ready_q.Top()->completionTime << " ";
            ready_q.Pop();
        }
        else if (ready_q.Top()->burstTime <= 0)
        {
            // std::cout << "here ";
            ready_q.Top()->completionTime = t;
            // std::cout << "D" << ready_q.Top()->completionTime << " ";
            ready_q.Pop();
        }
        else
        {
            std::cout << "here";
        }
    }
    // for (unsigned int i = 0; i < processesToExecute.size(); i++)
    // {
    //     if (processesToExecute.at(i).arrivalTime <= t)
    //     {
    //         ready_q.push(&(processesToExecute.at(i)));
    //     }
    //     else
    //     {
    //         if (ready_q.empty())
    //         {
    //             t++;
    //             i--;
    //         }
    //         else
    //         {
    //             t += ready_q.top()->burstTime;
    //             ready_q.top()->completionTime = t;
    //             ready_q.pop();
    //             this->nCS++;
    //             i--;
    //         }
    //     }
    // }

    // while (!ready_q.empty())
    // {
    //     t += ready_q.top()->burstTime;
    //     ready_q.top()->completionTime = t;
    //     ready_q.pop();
    //     this->nCS++;
    // }
    for (unsigned int i = 0; i < processesToExecute.size(); i++)
    {
        std::cout << processesToExecute.at(i).completionTime << " ";
    }

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);
}

DRRHA::~DRRHA()
{
}