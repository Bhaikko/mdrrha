// #include <iostream>

#include "./filehandler.h"
#include "./dataset_generator.h"

#include "./../include/MeanPriorityQueue.h"
#include "./../include/RoundRobin.h"
#include "./../include/SJF.h"
#include "./../include/DRRHA.h"
#include "./../include/mDRRHA.h"
#include "./../include/nDRRHA.h"
#include "./../include/HRRNHA.h"

int main()
{
    // GenerateRandomDataset(550, false);

    int test_case_no[] = {10, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    // int test_case_no[] = {500};
    int numTestCases = sizeof(test_case_no) / sizeof(int);

    for (int i = 0; i < numTestCases; i++)
    {
        std::vector<Process> processesToExecute = ReadProcessesFromFile(test_case_no[i]);

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

        RoundRobin roundRobin(processesToExecute, 10);
        roundRobin.RunAlgo();

        DRRHA drrha(processesToExecute);
        drrha.RunAlgo();

        MDRRHA mdrrha(processesToExecute);
        mdrrha.RunAlgo();

        NDRRHA ndrrha(processesToExecute);
        ndrrha.RunAlgo();

        HRRNHA hrrnha(processesToExecute);
        hrrnha.RunAlgo();

    }

    return 0;
}

// 10 50 100 150 200