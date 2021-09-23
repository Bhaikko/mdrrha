#include "./../include/RoundRobin.h"


RoundRobin::RoundRobin(std::vector<Process> processesToExecute, int quantum) : Algorithm(processesToExecute)
{
    this->name = "RR";
    this->quantum = quantum;
}

// Process* RoundRobin::getMinATProcess(std::vector<Process> processesToExecute)
// {
//     int min = INFINITY;
//     int index;
//     for(unsigned int i = 0; i < processesToExecute.size(); i++)
//     {
//         if(min > processesToExecute.at(i).arrivalTime)
//         {
//             min = processesToExecute.at(i).arrivalTime;
//             index = i;
//         }
//     }
//     return &processesToExecute.at(index);

// }
void RoundRobin::RunAlgo()
{
    Algorithm::RunAlgo();

    std::queue<Process*> rq;
    int currentTime = 0,
        index = 0;

    std::cout << processesToExecute.size() << std::endl;

    Process *p = &processesToExecute.at(index);
    // p->arrivalTime = INFINITY;
    rq.push(p);

    while(!rq.empty())
    {
        Process *p = rq.front();
        rq.pop();
        nCS++;

        if(p->burstTime < quantum)
        {
            currentTime += p->burstTime;
            p->burstTime = 0;
            p->completionTime = currentTime;
        }
        else
        {
            p->burstTime -= quantum;
            currentTime += quantum;
        }

        while(true)
        {  
            index++;
            Process *newP = &processesToExecute.at(index);
            if(newP->arrivalTime <= currentTime)
            {
                // newP->arrivalTime = INFINITY;
                rq.push(newP);
            }
            else break;
        }

        if(p->burstTime)
            rq.push(p);
        
    }

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    for (unsigned int i = 0; i < processesToExecute.size(); i++) {
         std::cout << processesToExecute[i].completionTime << std::endl;
    }

    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);

}

RoundRobin::~RoundRobin()
{

}
