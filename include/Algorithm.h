#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "./Process.h"
#include "./../src/filehandler.h"

class Algorithm
{
private:
    void CalculateMetrics();

protected:
    float avgTAT;       // Average Turn Around Time
    float avgWT;        // Average Waiting Time
    int nCS;            // Context Switches
    std::string name;   // Required as Key when exporting to CSV file

    std::vector<Process>* processesToExecute;

public:
    Algorithm(std::vector<Process>* processesToExecute);

    virtual void RunAlgo();
    
    void ProcessResult(bool bShouldPrintResults, bool bShouldWriteResults);

    ~Algorithm();
};