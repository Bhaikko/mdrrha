#include "./../include/HRRNHA.h"


HRRNHA::HRRNHA(std::vector<Process> processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "HRRNHA";
}

void HRRNHA::SortReadyQueue(int currentTime)
{
    // Calulate HRR of every process in Ready queue
    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        readyQueue[i]->responseRatio = (
            currentTime - readyQueue[i]->arrivalTime + readyQueue[i]->burstTime
        ) / (readyQueue[i]->burstTime * 1.0f);

        // std::cout << readyQueue[i]->responseRatio << " ";
    }

    // std::cout << std::endl;

    // Sort Processes based on HRR in decreasing order
    std::sort(readyQueue.begin(), readyQueue.end(), [](Process* first, Process* second) -> bool {
        if (abs(first->responseRatio - second->responseRatio) < 0.00001f) {
            return first->arrivalTime < second->arrivalTime;
        }

        return first->responseRatio > second->responseRatio;
    });
}

float HRRNHA::GetMean()
{
    float mean = 0.0f;
    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        mean += readyQueue[i]->burstTime;
    }

    return mean / (readyQueue.size() * 1.0f);
}

int HRRNHA::GetMedian()
{
    std::vector<Process*> queueCopy(readyQueue);
    std::sort(queueCopy.begin(), queueCopy.end(), [](Process* first, Process* second) -> bool {
        return first->burstTime < second->burstTime;
    });

    return queueCopy[queueCopy.size() / 2]->burstTime;
}

void HRRNHA::CalculateMeanAndSD()
{
    mean = GetMean(); 
    int sqrSum = 0;
    
    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        sqrSum += (readyQueue[i]->burstTime - mean) * (readyQueue[i]->burstTime - mean);
    }

    standardDeviation = sqrt(sqrSum / readyQueue.size()); // Calculate Standard Deviation

    // std::cout << mean << " " << standardDeviation << std::endl;

}

float HRRNHA::GetNormalDistribution()
{   

    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::normal_distribution<float> distribution(mean, standardDeviation);

    return distribution(gen);
}

void HRRNHA::FillTimeQuantums()
{
    // Only Consider This for metric
    // Compare this only with DRRHA
    CalculateMeanAndSD();

    for (unsigned int i = 0; i < readyQueue.size(); i++) {
        // int quantum = floor(
        //     (metric / 2.0f) + ((metric / 2.0f) / readyQueue[i]->burstTime)
        // );

        // tqs[readyQueue[i]->p_id] = quantum;


        tqs[readyQueue[i]->p_id] = floor(GetNormalDistribution());

    }
}

void HRRNHA::FillReadyQueueFromPending()
{
    for (unsigned int i = 0; i < processesToPushAfterRound.size(); i++) {
        readyQueue.push_back(processesToPushAfterRound[i]);
    }

    processesToPushAfterRound.clear();

}

void HRRNHA::RunAlgo()
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
        SortReadyQueue(currentTime);

        FillTimeQuantums();     // Using Mean as Heuristic

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

HRRNHA::~HRRNHA() { }


