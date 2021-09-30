#include "./../include/DRRHA.h"
#include "./../include/MeanPriorityQueue.h"

DRRHA::DRRHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "DRRHA";
}

void DRRHA::RunAlgo()
{
    Algorithm::RunAlgo();

    MeanPriorityQueue rq;
    int currentTime = processesToExecute[0].arrivalTime;


    unsigned int index = 0;
    while(index < processesToExecute.size())
    {  
        Process *newP = &processesToExecute.at(index);
        
        if(newP->arrivalTime <= currentTime) {
            rq.Push(newP);
        }
        else
            break;
        
        index++;
    } 

    while(rq.GetQueueSize() > 0)
    {

        Process *p = rq.Top();
        float quantum;
        float m = rq.GetMean();

        quantum = ceil((m/2) + (m/(2*p->burstTime)));
    
        rq.Execute(quantum, &currentTime, &nCS);

        nCS++;

        while(index < processesToExecute.size())
        {  
            Process *newP = &processesToExecute.at(index);
            
            if(newP->arrivalTime <= currentTime) {
                rq.Push(newP);
            }
            else
                break;
            
            index++;
        } 
        
    }

    nCS--;

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    ListCompletitionTimesOfProcesses();


    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);

}

DRRHA::~DRRHA() { }


