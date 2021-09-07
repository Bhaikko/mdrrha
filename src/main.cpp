#include <iostream>

// #include "./paths.h"
#include "./filehandler.h"

#include "./../include/RoundRobin.h"

int main()
{
    std::vector<Process>* processesToExecute = ReadProcessesFromFile();

    if (!processesToExecute) {
        return -1;
    }

    RoundRobin roundRobin(processesToExecute);

    roundRobin.RunAlgo();

    return 0;
}