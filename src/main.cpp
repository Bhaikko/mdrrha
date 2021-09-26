#include <iostream>

#include "./filehandler.h"

#include "./../include/MeanPriorityQueue.h"
#include "./../include/RoundRobin.h"
#include "./../include/SJF.h"
// #include "./../include/DRRHA.h"

int main()
{
    std::vector<Process> processesToExecute = ReadProcessesFromFile();

    if (processesToExecute.size() == 0)
    {
        std::cerr << "Error in Reading Processes." << std::endl;
        return -1;
    }

    RoundRobin roundRobin(processesToExecute, 3);

    roundRobin.RunAlgo();

    // SJF sjf(processesToExecute);

    // sjf.RunAlgo();

    // DRRHA drrha(processesToExecute, 2);

    // drrha.RunAlgo();

    return 0;
}