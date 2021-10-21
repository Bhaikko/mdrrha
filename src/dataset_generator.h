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

            if (bShouldGenerateArrivalTime) {
                data += std::to_string(rand() % ARRIVAL_TIME_UPPER_BOUND + ARRIVAL_TIME_LOWER_BOUND) + ", ";
            } else {
                data += std::to_string(0) + ", ";
            }

            data += std::to_string(rand() % BURST_TIME_UPPER_BOUND + BURST_TIME_LOWER_BOUND);

            data += "\n";
        }        
        
        std::fstream outputFile;
        outputFile.open(RANDOM_DATASET_FILE_PATH, std::ios_base::out);

        if (!outputFile) {
            std::cerr << "Cannot open " << RANDOM_DATASET_FILE_PATH << std::endl;
            return -1;
        }

        outputFile << "\"Arrival Time\", \"Burst Time\"\n";
        outputFile << data;

        return 1;
    }

#endif

