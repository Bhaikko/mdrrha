#include "./../include/nDRRHA.h"


nDRRHA::nDRRHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "nDRRHA";
}

void nDRRHA::RunAlgo()
{
    Algorithm::RunAlgo();

    MeanPriorityQueue readyQueue;
    int currentTime = processesToExecute[0].arrivalTime;

    unsigned int index = 0;
    while(index < processesToExecute.size())
    {  
        Process *newProcess = &processesToExecute.at(index);
        
        if(newProcess->arrivalTime <= currentTime) {
            readyQueue.Push(newProcess);
        }
        else
            break;
        
        index++;
    } 

    readyQueue.SortQueue();
    int timeQuantumToExecute;

    while(readyQueue.GetQueueSize() > 0)
    {
        Process* currentProcess = readyQueue.Top();
        float mean = readyQueue.GetNormalDistribution();
        // std::cout<<mean<<" ";

        timeQuantumToExecute = floor((mean / 2) + (mean / (2 * currentProcess->burstTime)));
        // std::cout << timeQuantumToExecute << " " << currentProcess->burstTime << std::endl;
        
        if (timeQuantumToExecute >= currentProcess->burstTime)
        {
            readyQueue.Pop();
            currentTime += currentProcess->burstTime;
            currentProcess->completionTime = currentTime;
            currentProcess->burstTime = 0;   
        } else {
            readyQueue.Pop();
            
            currentTime += timeQuantumToExecute;
            currentProcess->burstTime -= timeQuantumToExecute;

            // TODO: Figure out later when changing equations
            
            // if (currentProcess->burstTime < timeQuantumToExecute){

            //     // std::cout << "IF: " << currentProcess->p_id << " " << currentProcess->burstTime << std::endl;
                
            //     currentTime += currentProcess->burstTime;
            //     currentProcess->burstTime = 0;
            //     currentProcess->completionTime = currentTime;                
            // } else {
            //     // std::cout << "ELSE: " << currentProcess->p_id << " " << currentProcess->burstTime << std::endl;
            //     readyQueue.Push(currentProcess);
            // }
            

            readyQueue.Push(currentProcess);
        }
        

        nCS++;

        while(index < processesToExecute.size())
        {  
            Process* newProcess = &processesToExecute.at(index);
            
            if(newProcess->arrivalTime <= currentTime) {
                readyQueue.Push(newProcess);
                readyQueue.SortQueue();
            }
            else
                break;
            
            index++;
        } 
        
        if(readyQueue.Empty() && index < processesToExecute.size()){
            currentTime = processesToExecute.at(index).arrivalTime;
            Process* newProcess = &processesToExecute.at(index);
            readyQueue.Push(newProcess);
            readyQueue.SortQueue();
            index++;
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

nDRRHA::~nDRRHA() { }


