#include "./../include/DRRHA.h"


DRRHA::DRRHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "DRRHA";
}

/*
void DRRHA::RunAlgo()
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
        float mean = readyQueue.GetMean();
        // std::cout<<mean<<" ";

        timeQuantumToExecute = floor((mean / 2) + (mean / (2 * currentProcess->burstTime)));
        // std::cout << timeQuantumToExecute << " " << currentProcess->burstTime << std::endl;
        
        if (timeQuantumToExecute >= currentProcess->burstTime)
        {
            readyQueue.Pop();
            currentProcess->Execute(0, currentTime);

            currentTime += currentProcess->burstTime;
            currentProcess->completionTime = currentTime;
            currentProcess->burstTime = 0;   
        } else {
            readyQueue.Pop();
            
            currentProcess->Execute(0, currentTime);

            currentTime += timeQuantumToExecute;
            currentProcess->burstTime -= timeQuantumToExecute;

            // TODO: Figure out later when changing equations
            
            // if (currentProcess->burstTime <= timeQuantumToExecute){
            //     std::cout << "IF: " << currentProcess->p_id << " " << currentProcess->burstTime << std::endl;
                
            //     currentTime += currentProcess->burstTime;
            //     currentProcess->burstTime = 0;
            //     currentProcess->completionTime = currentTime;                
            // } else {
            //     std::cout << "ELSE: " << currentProcess->p_id << " " << currentProcess->burstTime << std::endl;
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
    ProcessResult(true, true);

}

*/

void DRRHA::SortReadyQueue()
{
    std::sort(readyQueue.begin(), readyQueue.end(), [](Process* first, Process* second) -> bool {
        return first->burstTime < second->burstTime;
    });
}

float DRRHA::GetMean()
{
    float mean = 0.0f;
    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        mean += readyQueue[i]->burstTime;
    }

    return mean / (readyQueue.size() * 1.0f);
}

std::vector<int> DRRHA::FillTimeQuantums()
{
    std::vector<int> timequantums(readyQueue.size(), 0);

    float mean = GetMean();

    for (unsigned int i = 0; i < timequantums.size(); i++) {
        timequantums[i] = floor(
            (mean / 2.0f) + ((mean / 2.0f) / readyQueue[i]->burstTime)
        );

        std::cout << timequantums[i] << " ";
    }

    std::cout << std::endl;

    return timequantums;
}

void DRRHA::FillReadyQueueFromPending()
{
    for (unsigned int i = 0; i < processesToPushAfterRound.size(); i++) {
        readyQueue.push_back(processesToPushAfterRound[i]);
    }

    processesToPushAfterRound.clear();

}

void DRRHA::RunAlgo()
{
    Algorithm::RunAlgo();

    int currentTime = processesToExecute[0].arrivalTime;

    unsigned int index = 0;
    while(index < processesToExecute.size())
    {  
        Process *newProcess = &processesToExecute.at(index);
        
        if(newProcess->arrivalTime <= currentTime) {
            readyQueue.push_back(newProcess);
        }
        else
            break;
        
        index++;
    } 

    while (index < processesToExecute.size()) {
        // FillReadyQueueFromPending();
        SortReadyQueue();

        std::vector<int> timequantums = FillTimeQuantums();

        for (unsigned int i = 0; i < readyQueue.size(); i++) {
            Process* currentProcess = readyQueue[i];

            if (timequantums[i] >= currentProcess->burstTime) {
                // currentProcess->Execute(0, currentTime);
                currentTime += currentProcess->burstTime;
                currentProcess->completionTime = currentTime;
                currentProcess->burstTime = 0;   
            } else {
                currentTime += timequantums[i];
                currentProcess->completionTime -= currentTime;
            }

            if (currentProcess->burstTime < timequantums[i]) {
                currentTime += currentProcess->burstTime;
                currentProcess->completionTime = currentTime;
                currentProcess->burstTime = 0;

                readyQueue.erase(readyQueue.begin() + i);

                timequantums = FillTimeQuantums();

            } else {
                readyQueue.erase(readyQueue.begin() + i);
                readyQueue.push_back(currentProcess);
            }

            while (index < processesToExecute.size()) {  
                Process* newProcess = &processesToExecute.at(index);
                
                if(newProcess->arrivalTime <= currentTime) {
                    readyQueue.push_back(newProcess);
                    SortReadyQueue();

                    timequantums = FillTimeQuantums();
                }
                else
                    break;
                
                index++;
            } 

            nCS++;
        }

        // if (readyQueue.Empty() && index < processesToExecute.size()) {
        if (index < processesToExecute.size()) {
            currentTime = processesToExecute.at(index).arrivalTime;
            Process* newProcess = &processesToExecute.at(index);
            readyQueue.push_back(newProcess);
            SortReadyQueue();

            timequantums = FillTimeQuantums();
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


