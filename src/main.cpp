#include <iostream>
#include <fstream>
#include <vector>

#include "./../include/Process.h"
#include "./../include/RoundRobin.h"

std::string INPUT_FILE_PATH = "./src/sample_input.csv";

// Code to import data from csv file
std::vector<Process>* FillProcesses()
{
    std::vector<Process>* processesToExecute = new std::vector<Process>();

    std::fstream dataset(INPUT_FILE_PATH, std::ios::in);
    if (!dataset) {
        std::cerr << "Cannot Open " << INPUT_FILE_PATH << std::endl;
        return nullptr;
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

        processesToExecute->push_back(Process(
            p_id++,
            arrivalTime,
            burstTime
        ));
    }

    return processesToExecute;

}

int main()
{
    std::vector<Process>* processesToExecute = FillProcesses();

    if (!processesToExecute) {
        return -1;
    }

    RoundRobin roundRobin(processesToExecute);

    roundRobin.RunAlgo();

    return 0;
}