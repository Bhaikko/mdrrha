#include "./../include/RoundRobin.h"

RoundRobin::RoundRobin(std::vector<Process>* processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "RR";
}

void RoundRobin::RunAlgo(int quantum)
{
    Algorithm::RunAlgo();

    int *rem_bt = new int[processesToExecute->size()];
    int *wt = new int[processesToExecute->size()];
    int *tat = new int[processesToExecute->size()];

    int t = 0; // current time

    // Initialising remainig burst time of processes with burst times
    for(unsigned int i = 0; i < processesToExecute->size(); rem_bt[i++] = processesToExecute->at(i++).burstTime);

    // Calculating waiting time of all processes
    while(true){
        bool done = true;
        for(unsigned int i = 0; i < processesToExecute->size(); i++){
            if(rem_bt[i] > 0){
                done = false;
                if(rem_bt[i] > quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t += rem_bt[i];
                    wt[i] = t - processesToExecute->at(i).burstTime;
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == true)
            break;
    }

    // Calculating turn-around time of all processes
    for(unsigned int i = 0; i < processesToExecute->size(); i++){
        tat[i++] = processesToExecute->at(i++).burstTime + wt[i++];
    }

    for (unsigned int i = 0; i < processesToExecute->size(); i++) {        
        
        std::cout << "Processing " << i << " process." << std::endl;
        printf("Processing %i process. AT: %i, BT: %i \n", 
            processesToExecute->at(i).p_id,
            processesToExecute->at(i).arrivalTime,
            processesToExecute->at(i).burstTime
        );

        // Calculating completion time of every process
        processesToExecute->at(i).completionTime = tat[i] + processesToExecute->at(i).arrivalTime;
    }

    // Generating Random Context Switches for Testing
    this->nCS = rand() % 50 + 1;    

    Algorithm::CalculateMetrics();

    std::cout << this->name << " Ended for " << processesToExecute->size() << " processes." << std::endl;

    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult();

}

RoundRobin::~RoundRobin()
{

}