// #include <iostream>

#include "./filehandler.h"

#include "./../include/MeanPriorityQueue.h"
#include "./../include/RoundRobin.h"
#include "./../include/SJF.h"
#include "./../include/DRRHA.h"

int main()
{
    int test_case_no[] = {10, 50, 100, 150, 200};

    // for (int i = 0; test_case_no[i]; i++)
    for (int i = 0; i < 1; i++)
    {
        std::vector<Process> processesToExecute = ReadProcessesFromFile(test_case_no[4]);

        if (processesToExecute.size() == 0)
        {
            std::cerr << "Error in Reading Processes." << std::endl;
            return -1;
        }

        // std::cout << processesToExecute.size() << std::endl;

        // for (unsigned int i = 0; i < processesToExecute.size(); i++) {
        //     std::cout << processesToExecute[i].p_id << " " << processesToExecute[i].arrivalTime << " " << processesToExecute[i].burstTime << std::endl;
        // }

        std::cout << std::endl;

        SJF sjf(processesToExecute);

        sjf.RunAlgo();

        // RoundRobin roundRobin(processesToExecute, 10);

        // roundRobin.RunAlgo();

        DRRHA drrha(processesToExecute);

        drrha.RunAlgo();
    }
    return 0;
}

// 10 50 100 150 200