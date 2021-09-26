#pragma once

#include <iostream>

class Process
{

private:
int originalBT;

public:
    int arrivalTime;
    float burstTime;    // Discuss about this
    int p_id;
    float completionTime;


public:
    Process(int p_id, int arrivalTime, int burstTime);

    bool Execute(int executionTime);

    ~Process();

public:
    int GetOriginalBT() { return originalBT; }
};
