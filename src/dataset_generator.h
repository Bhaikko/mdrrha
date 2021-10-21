#pragma once

#include <cstdlib>
#include <time.h>

#include "./filehandler.h"

#ifndef DATASET_RANDOM
    #define DATASET_RANDOM

    /*
        RANDOMLY Generated Dataset 
        Burst Time Range: 100 - 400
        Arrival Time Range: 10 - 100
    */

    #define BURST_TIME_LOWER_BOUND 100
    #define BURST_TIME_UPPER_BOUND 400
    #define ARRIVAL_TIME_LOWER_BOUND 10
    #define ARRIVAL_TIME_UPPER_BOUND 100

    
    inline int GenerateRandomDataset(int numOfProcesses, bool bShouldGenerateArrivalTime = false)
    {
        std::srand(time(nullptr));
     
        std::string data = "";

        for (int i = 0; i < numOfProcesses; i++) {
            std::string currentProcess = "";

            currentProcess += std::to_string(rand() % BURST_TIME_UPPER_BOUND + BURST_TIME_LOWER_BOUND);

            if (bShouldGenerateArrivalTime) {
                currentProcess += std::to_string(rand() % ARRIVAL_TIME_UPPER_BOUND + ARRIVAL_TIME_LOWER_BOUND);
            }

            currentProcess += "\n";
        }        
        
        std::fstream outputFile;
        outputFile.open(RANDOM_DATASET_FILE_PATH, std::ios_base::out);

        outputFile << "\"Arrival Time\", \"Burst Time\"";
        outputFile << data;



        return 1;
    }

#endif

