#include <iostream>

// Only For Random Generation
#include <stdlib.h>
#include <time.h>

// #include "./paths.h"
#include "./filehandler.h"

#include "./../include/RoundRobin.h"

int main()
{
    srand(time(NULL));
    
    std::vector<Process>* processesToExecute = ReadProcessesFromFile();

    if (!processesToExecute) {
        return -1;
    }

    RoundRobin roundRobin(processesToExecute, 2);

    roundRobin.RunAlgo();

    return 0;
}