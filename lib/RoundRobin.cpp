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
    int currentTime = processesToExecute[0].arrivalTime;    // Arrival time cannot always be 0

    int *original_bt = new int[processesToExecute.size()];
    for(unsigned int i = 0; i < processesToExecute.size(); i++)
    {
        original_bt[i] = processesToExecute.at(i).burstTime;
    }

    std::cout << processesToExecute.size() << std::endl;

    Process *p = &processesToExecute.at(0);
    rq.push(p);

    unsigned int index = 1;

    while(!rq.empty())
    {
        Process *p = rq.front();
        rq.pop();
        
        nCS++;

        if(p->burstTime <= quantum)
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

        while(index < processesToExecute.size())
        {  
            Process *newP = &processesToExecute.at(index);
            
            if(newP->arrivalTime <= currentTime)
                rq.push(newP);
            else
                break;
            
            index++;
        }

        if(p->burstTime)
            rq.push(p);
        
    }

    nCS--;

    for(unsigned int i = 0; i < processesToExecute.size(); i++)
    {
        processesToExecute.at(i).burstTime = original_bt[i];
    }

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // for (unsigned int i = 0; i < processesToExecute.size(); i++) {
    //      std::cout << processesToExecute[i].completionTime << std::endl;
    // }


    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);


}

RoundRobin::~RoundRobin()
{

}
