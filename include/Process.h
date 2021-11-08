#pragma once

#include <iostream>

class Process
{

private:
    int originalBT;

public:
    int arrivalTime;
    int burstTime;
    int p_id;
    int completionTime;
    int responseTime;
    float responseRatio;

public:
    Process(int p_id, int arrivalTime, int burstTime);

    bool Execute(int executionTime, int currentTime);

    ~Process();

public:
    int GetOriginalBT() { return originalBT; }
};
