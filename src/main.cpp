#include <iostream>
#include <vector>

#include "./../include/Process.h"
#include "./../include/RoundRobin.h"

std::vector<Process>* processesToExecute;

void FillProcesses()
{
    // Later will be imported using CSV File

    processesToExecute = new std::vector<Process>();

    processesToExecute->push_back(Process(1, 1, 2));
    processesToExecute->push_back(Process(2, 1, 2));
    processesToExecute->push_back(Process(3, 1, 2));
    processesToExecute->push_back(Process(4, 1, 2));
    processesToExecute->push_back(Process(5, 1, 2));
}

int main()
{
    FillProcesses();

    RoundRobin roundRobin(processesToExecute);

    roundRobin.RunAlgo();

    return 0;
}