#include <iostream>
#include <vector>

#include "./../include/Process.h"
#include "./../include/RoundRobin.h"

std::vector<Process>* processesToExecute;

void FillProcesses()
{
    // Code to import data from csv file
    // Sample csv file for proccesses is in src folder
    // Look CSV format for more info
    // https://people.sc.fsu.edu/~jburkardt/data/csv/csv.html
    // Writemode should be ReadOnly

    // For p_id, use counter to allocate just like SQL does

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