#pragma once

#include <iostream>

class Process
{

public:
    int arrivalTime;
    float burstTime;
    int p_id;
    float completionTime;

public:
    Process(int p_id, int arrivalTime, int burstTime);
    // Process(Process &p);

    bool Execute(int executionTime);

    ~Process();
};
