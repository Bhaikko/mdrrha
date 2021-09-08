#include "./../include/RoundRobin.h"

RoundRobin::RoundRobin(std::vector<Process>* processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "RR";
}

void RoundRobin::RunAlgo()
{
    Algorithm::RunAlgo();

    for (unsigned int i = 0; i < processesToExecute->size(); i++) {        
        // Write Algo Here
        // std::cout << "Processing " << i << " process." << std::endl;
        // printf("Processing %i process. AT: %i, BT: %i \n", 
        //     processesToExecute->at(i).p_id,
        //     processesToExecute->at(i).arrivalTime,
        //     processesToExecute->at(i).burstTime
        // );

        // Generating Random Completion Time for Testing
        processesToExecute->at(i).completionTime = rand() % 50 + processesToExecute->at(i).arrivalTime;
    }

    // Generating Random Context Switches for Testing
    this->nCS = rand() % 50 + 1;    

    std::cout << this->name << " Ended for " << processesToExecute->size() << " processes." << std::endl;

    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult();

}

RoundRobin::~RoundRobin()
{

}