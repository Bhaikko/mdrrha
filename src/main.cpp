#include <iostream>

// Only For Random Generation
#include <stdlib.h>
#include <time.h>

// #include "./paths.h"
#include "./filehandler.h"

#include "./../include/RoundRobin.h"

// Will be Removed After implementing CPU Schdeduling Algos

int main()
{
    srand(time(NULL));
    
    std::vector<Process>* processesToExecute = ReadProcessesFromFile();

    if (!processesToExecute) {
        return -1;
    }

    RoundRobin roundRobin(processesToExecute);

    roundRobin.RunAlgo(2);

    return 0;
}