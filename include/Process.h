#pragma once

#include <iostream>

class Process 
{

public:
    int arrivalTime;
    int burstTime;
    int p_id;
    int completionTime;

public:
    Process(int p_id, int arrivalTime, int burstTime);

    bool Execute(int executionTime);
    
    ~Process();
};
