#pragma once

#include <iostream>

class Process 
{

private:
    int arrivalTime;
    int burstTime;
    int p_id;

public:
    Process(int p_id, int arrivalTime, int burstTime);

    bool Execute(int executionTime);
    
    ~Process();
};
