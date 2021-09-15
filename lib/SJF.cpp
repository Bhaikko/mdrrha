#include "./../include/SJF.h"

SJF::SJF(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "SJF";
}

void SJF::RunAlgo()
{
    Algorithm::RunAlgo();
    
    std::priority_queue<Process *, std::vector<Process *>, CompareProcess> ready_q;

    int t = 0; // current time
    for (unsigned int i = 0; i < processesToExecute.size(); i++)
    {
        if (processesToExecute.at(i).arrivalTime <= t)
        {
            ready_q.push(&(processesToExecute.at(i)));
        }
        else
        {
            if (ready_q.empty())
            {
                t++;
                i--;
            }
            else
            {
                t += ready_q.top()->burstTime;
                ready_q.top()->completionTime = t;
                ready_q.pop();
                this->nCS++;
                i--;
            }
        }
    }

    while (!ready_q.empty())
    {
        t += ready_q.top()->burstTime;
        ready_q.top()->completionTime = t;
        ready_q.pop();
        this->nCS++;
    }

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);
}

SJF::~SJF()
{

}