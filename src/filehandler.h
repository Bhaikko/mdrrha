#pragma once

#include <fstream>
#include <vector>
#include <algorithm>

#include "./paths.h"
#include "./../include/Process.h"

#ifndef FILE_HANDLER
    #define FILE_HANDLER 1
    // Code to import data from csv file
    // The below code only works for specific database schema
    // Won't work as General CSV Parser
    inline std::vector<Process> ReadProcessesFromFile()
    {
        std::vector<Process> processesToExecute;

        std::fstream dataset(INPUT_FILE_PATH, std::ios::in);
        if (!dataset) {
            std::cerr << "Cannot Open " << INPUT_FILE_PATH << std::endl;
            return processesToExecute;
        }

        std::string currentLine;
        int p_id = 0;

        while (std::getline(dataset, currentLine)) {
            if (p_id == 0) {
                p_id++;
                continue;
            }

            std::string currentProcessDetail;
            int arrivalTime, burstTime;

            // Processing Each Line of .CSV file
            for (unsigned int i = 0; i < currentLine.length(); i++) {
                if (currentLine[i] == ',') {
                    arrivalTime = std::stoi(currentProcessDetail);
                    currentProcessDetail = "";
                    continue;
                }

                currentProcessDetail.push_back(currentLine[i]);
            }

            burstTime = std::stoi(currentProcessDetail);

            processesToExecute.push_back(Process(
                p_id++,
                arrivalTime,
                burstTime
            ));
        }

        sort(
            processesToExecute.begin(), 
            processesToExecute.end(), 
            [](Process first, Process second) -> bool {
                return first.arrivalTime < second.arrivalTime;
        });

        return processesToExecute;
    }


    inline bool isFileEmpty(std::string filepath)
    {
        std::fstream outputFileToCheck;
        outputFileToCheck.open(filepath, std::ios_base::in);

        int count = 0;
        std::string currentLine;
        while (std::getline(outputFileToCheck, currentLine)) {
            count++;
            break;
        }

        outputFileToCheck.close();

        return count == 0;
    }

    inline void WriteToCSV(std::string data)
    {
        std::fstream outputFile;
        outputFile.open(OUTPUT_FILE_PATH, std::ios_base::app);

        if (!outputFile) {
            std::cout << "Error Writing to File " << std::endl;
        }

        if (isFileEmpty(OUTPUT_FILE_PATH)) {
            outputFile << "name, #cases, avgTAT, avgWT, nCS";
        }

        outputFile << data;
    }
#endif