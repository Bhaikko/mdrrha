#pragma once

#include <vector>
#include <string>

#include "./Process.h"

class Algorithm
{
public:
    float avgTAT;       // Average Turn Around Time
    float avgWT;        // Average Waiting Time
    int nCS;            // Context Switches
    std::string name;   // Required as Key when exporting to CSV file

    std::vector<Process>* processesToExecute;

public:
    Algorithm(std::vector<Process>* processesToExecute);

    virtual void RunAlgo();

    ~Algorithm();
};