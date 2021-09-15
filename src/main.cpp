#include <iostream>
//for priority queue
#include <queue>
// Only For Random Generation
#include <stdlib.h>
#include <time.h>

// #include "./paths.h"
#include "./filehandler.h"

#include "./../include/RoundRobin.h"
#include "./../include/SJF.h"

int main()
{
    srand(time(NULL));

    std::vector<Process> processesToExecute = ReadProcessesFromFile();

    if (processesToExecute.size() == 0)
    {
        std::cerr << "Error in Reading Processes." << std::endl;
        return -1;
    }

    // RoundRobin roundRobin(processesToExecute, 2);

    // roundRobin.RunAlgo();
    SJF sjf(processesToExecute);

    sjf.RunAlgo();

    return 0;
}