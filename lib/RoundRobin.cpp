#include "./../include/RoundRobin.h"

RoundRobin::RoundRobin(std::vector<Process> processesToExecute, int quantum) : Algorithm(processesToExecute)
{
    this->name = "RR";
    this->quantum = quantum;
}

void RoundRobin::RunAlgo()
{
    Algorithm::RunAlgo();

    // int *rem_bt = new int[processesToExecute.size()];

    // int *wt = new int[processesToExecute.size()];
    // int *tat = new int[processesToExecute.size()];

    // int t = 0; // current time

    // // Initialising remainig burst time of processes with burst times
    // for(unsigned int i = 0; i < processesToExecute.size(); rem_bt[i++] = processesToExecute.at(i++).burstTime);

    // // Calculating waiting time of all processes
    // while(true){
    //     bool done = true;
    //     for(unsigned int i = 0; i < processesToExecute.size(); i++){
    //         if(rem_bt[i] > 0){
    //             done = false;
    //             if(rem_bt[i] > quantum){
    //                 t += quantum;
    //                 rem_bt[i] -= quantum;

    //                 processesToExecute.at(i).burstTime -= quantum;

    //                 if (processesToExecute.at(i).Execute(quantum)) {
    //                     // Dont push in queue
    //                     // Update Completion time to Current Time
    //                 } else {
    //                     // Push into queue
    //                 }
    //             }
    //             else{
    //                 t += rem_bt[i];
    //                 wt[i] = t - processesToExecute.at(i).burstTime;
    //                 rem_bt[i] = 0;
    //             }
    //         }
    //     }
    //     if(done == true)
    //         break;
    // }

    // // Calculating turn-around time of all processes
    // for(unsigned int i = 0; i < processesToExecute.size(); i++){
    //     tat[i++] = processesToExecute.at(i++).burstTime + wt[i++];
    // }

    for (unsigned int i = 0; i < processesToExecute.size(); i++) {        
        
        std::cout << "Processing " << i << " process." << std::endl;
        printf("Processing %i process. AT: %i, BT: %i \n", 
            processesToExecute.at(i).p_id,
            processesToExecute.at(i).arrivalTime,
            processesToExecute.at(i).burstTime
        );
    }

    // Algorithm::CalculateMetrics();

    std::cout << this->name << " Ended for " << processesToExecute.size() << " processes." << std::endl;

    // Read Function Definition before calling
    // Prints Result on Console after Calculating avgTAT, etc
    // Write results such as avgTAT, avgWT, nCS to external .csv file
    ProcessResult(true, false);

}

RoundRobin::~RoundRobin()
{

}