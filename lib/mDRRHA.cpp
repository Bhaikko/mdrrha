#include "./../include/mDRRHA.h"


MDRRHA::MDRRHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "MDRRHA";
}

void MDRRHA::SortReadyQueue()
{
    std::sort(readyQueue.begin(), readyQueue.end(), [](Process* first, Process* second) -> bool {
        return first->burstTime < second->burstTime;
    });
}

int MDRRHA::GetMedian()
{
    std::vector<Process*> queueCopy(readyQueue);
    std::sort(queueCopy.begin(), queueCopy.end(), [](Process* first, Process* second) -> bool {
        return first->burstTime < second->burstTime;
    });

    return queueCopy[queueCopy.size() / 2]->burstTime;
}

void MDRRHA::FillTimeQuantums()
{
    int median = GetMedian();

    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        int quantum = floor(
            (median / 2.0f) + ((median / 2.0f) / readyQueue[i]->burstTime)
        );

        tqs[readyQueue[i]->p_id] = quantum;
    }
}

void MDRRHA::FillReadyQueueFromPending()
{
    for (unsigned int i = 0; i < processesToPushAfterRound.size(); i++) {
        readyQueue.push_back(processesToPushAfterRound[i]);
    }

    processesToPushAfterRound.clear();

}

void MDRRHA::RunAlgo()
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

    while (index < processesToExecute.size() || readyQueue.size() > 0) {
        FillReadyQueueFromPending();
        SortReadyQueue();

        FillTimeQuantums();

        for (unsigned int i = 0; i < readyQueue.size(); i++) {
            nCS++;

            Process* currentProcess = readyQueue[i];
            currentProcess->Execute(0, currentTime);

            // First Execution
            if (tqs[currentProcess->p_id] >= currentProcess->burstTime) {
                currentTime += currentProcess->burstTime;
                currentProcess->completionTime = currentTime;
                currentProcess->burstTime = 0;

            } else {
                currentTime += tqs[currentProcess->p_id];
                currentProcess->burstTime -= tqs[currentProcess->p_id];
            }

            if (currentProcess->burstTime < tqs[currentProcess->p_id]) {
                currentTime += currentProcess->burstTime;
                currentProcess->completionTime = currentTime;
                currentProcess->burstTime = 0;
            }

        }

        std::vector<Process*> transferQueue;

        for (unsigned int i = 0; i < readyQueue.size(); i++) {
            Process* currentProcess = readyQueue[i];

            if (currentProcess->burstTime != 0) {
                transferQueue.push_back(readyQueue[i]);
            }
        }

        readyQueue = transferQueue;

        bool bNewProcessArrived = false;

        while (index < processesToExecute.size()) {  
            Process* newProcess = &processesToExecute.at(index);
            
            if(newProcess->arrivalTime <= currentTime) {
                readyQueue.push_back(newProcess);
                bNewProcessArrived = true;
            }
            else
                break;
            
            index++;
        } 

        if (!bNewProcessArrived) {
            if (index < processesToExecute.size()) {
                currentTime = processesToExecute.at(index).arrivalTime;
                Process* newProcess = &processesToExecute.at(index);
                readyQueue.push_back(newProcess);
                index++;
            }
        }
    }

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // ListCompletitionTimesOfProcesses();


    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, true);

}

MDRRHA::~MDRRHA() { }


