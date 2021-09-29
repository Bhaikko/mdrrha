#include "./test_DRRHA.h"
#include "./test_MeanPriorityQueue.h"
#include<cmath>

test_DRRHA::test_DRRHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "DRRHA";
}

void test_DRRHA::RunAlgo()
{
    Algorithm::RunAlgo();

    MeanPriorityQueue rq;
    int currentTime = processesToExecute[0].arrivalTime;

    // Process *p = &processesToExecute.at(0);
    // rq.Push(p);

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
    
        rq.Execute_extended(quantum, &currentTime, &nCS);

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

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    for (unsigned int i = 0; i < processesToExecute.size(); i++) {
         std::cout << processesToExecute[i].completionTime << std::endl;
    }


    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);

}



