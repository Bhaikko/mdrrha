#include "./../include/RoundRobin.h"


RoundRobin::RoundRobin(std::vector<Process> processesToExecute, int quantum) : Algorithm(processesToExecute)
{
    this->name = "RR";
    this->quantum = quantum;
}

void RoundRobin::RunAlgo()
{
    Algorithm::RunAlgo();

    std::queue<Process*> rq;
    int currentTime = processesToExecute[0].arrivalTime;

    Process *p = &processesToExecute.at(0);
    rq.push(p);

    unsigned int index = 1;

    // This is ending Before all processes execute
    while(!rq.empty())
    {
        Process *p = rq.front();
        rq.pop();
        
        nCS++;

        std::cout << p->arrivalTime << std::endl;

        if(p->burstTime <= quantum)
        {
            currentTime += p->burstTime;
            p->burstTime = 0;
            p->completionTime = currentTime;
        }
        else
        {
            p->burstTime -= quantum;

            if (p->burstTime < 0) {
                p->burstTime = 0;
            }

            currentTime += quantum;
        }

        while(index < processesToExecute.size())
        {  
            Process *newP = &processesToExecute.at(index);

            std::cout << newP->arrivalTime << std::endl;
            
            if(newP->arrivalTime <= currentTime)
                rq.push(newP);
            else
                break;
            
            index++;
        }

        if(p->burstTime > 0) {
            rq.push(p);
        }
        
    }

    nCS--;

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // ListCompletitionTimesOfProcesses();

    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);

}

RoundRobin::~RoundRobin()
{

}
