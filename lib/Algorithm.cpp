#include "./../include/Algorithm.h"

Algorithm::Algorithm(std::vector<Process> processesToExecute)
{
    this->avgTAT = 0.0f;
    this->avgWT = 0.0f;
    this->nCS = 0;
    this->processesToExecute = processesToExecute;
}

void Algorithm::RunAlgo()
{
    std::cout << name << " Started for " << this->processesToExecute.size() << " processes." << std::endl;
}

void Algorithm::CalculateMetrics()
{
    int totalTurnaroundTime = 0,
        totalWaitTime = 0;

    for (unsigned int i = 0; i < this->processesToExecute.size(); i++)
    {
        totalTurnaroundTime += (this->processesToExecute.at(i).completionTime - this->processesToExecute.at(i).arrivalTime);

        totalWaitTime += (this->processesToExecute.at(i).completionTime - this->processesToExecute.at(i).arrivalTime -
                          this->processesToExecute.at(i).burstTime);
    }

    this->avgTAT = totalTurnaroundTime * 1.0f / processesToExecute.size();
    this->avgWT = totalWaitTime * 1.0f / processesToExecute.size();
}

void Algorithm::ProcessResult(bool bShouldPrintResults, bool bShouldWriteResults = false)
{
    CalculateMetrics();

    if (bShouldPrintResults)
    {
        std::cout << std::endl;

        std::cout << "Name: " << name << std::endl;
        std::cout << "Test Cases: " << processesToExecute.size() << std::endl;
        std::cout << "Average TAT: " << avgTAT << std::endl;
        std::cout << "Average WT: " << avgWT << std::endl;
        std::cout << "Context Switches: " << nCS << std::endl;

        std::cout << std::endl;
    }

    if (bShouldWriteResults)
    {
        // File format mentioned below for writing
        /*
            name, numberoftestcases, avgTAT, avgWT, nCS
            RR, 2, 3.23, 4.24, 5

        */

        std::string resultToAppend =
            "\n" +
            this->name + "," +
            std::to_string(this->processesToExecute.size()) + "," +
            std::to_string(this->avgTAT) + "," +
            std::to_string(this->avgWT) + "," +
            std::to_string(this->nCS);

        WriteToCSV(resultToAppend);
    }
}

Algorithm::~Algorithm()
{
    
}