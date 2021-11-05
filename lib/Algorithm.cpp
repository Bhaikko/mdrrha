#include "./../include/Algorithm.h"

Algorithm::Algorithm(std::vector<Process> processesToExecute)
{
    this->avgTAT = 0.0f;
    this->avgWT = 0.0f;
    this->avgRT = 0.0f;
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
        totalWaitTime = 0,
        totalResponseTime = 0;

    for (unsigned int i = 0; i < this->processesToExecute.size(); i++)
    {
        totalTurnaroundTime += (this->processesToExecute.at(i).completionTime - this->processesToExecute.at(i).arrivalTime);

        totalWaitTime += ((this->processesToExecute.at(i).completionTime - this->processesToExecute.at(i).arrivalTime) -
                          this->processesToExecute.at(i).GetOriginalBT());

        totalResponseTime += ((this->processesToExecute.at(i)).responseTime - this->processesToExecute.at(i).arrivalTime);
    }

    this->avgTAT = totalTurnaroundTime * 1.0f / processesToExecute.size();
    this->avgWT = totalWaitTime * 1.0f / processesToExecute.size();
    this->avgRT = totalResponseTime * 1.0f / processesToExecute.size();
}

void Algorithm::ProcessResult(bool bShouldPrintResults, bool bShouldWriteResults = false)
{
    CalculateMetrics();

    if (bShouldPrintResults)
    {
        std::cout << std::endl;

        std::cout << "Name: " << name << std::endl;
        std::cout << "Processes Executed: " << processesToExecute.size() << std::endl;
        std::cout << "Average TAT: " << avgTAT << std::endl;
        std::cout << "Average WT: " << avgWT << std::endl;
        std::cout << "Average RT: " << avgRT << std::endl;
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
            std::to_string(this->avgRT) + "," +
            std::to_string(this->nCS);

        WriteToCSV(resultToAppend);
    }
}

void Algorithm::ListCompletitionTimesOfProcesses()
{
    std::cout << std::endl;
    
    std::cout << "Printing Completition Times." << std::endl;
    for (unsigned int i = 0; i < processesToExecute.size(); i++) {
        std::cout << 
            "P_ID: " <<
            processesToExecute[i].p_id << ": " << 
            processesToExecute[i].burstTime << ": " <<
            processesToExecute[i].completionTime << ": "  
        << std::endl;
    }

    std::cout << std::endl;
}

Algorithm::~Algorithm()
{
    
}