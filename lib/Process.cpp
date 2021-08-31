#include "./../include/Process.h"

Process::Process(int p_id, int arrivalTime, int burstTime)
{
    this->p_id = p_id;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
}

bool Process::Execute(int executionTime) 
{
    burstTime -= executionTime;

    return burstTime > 0 ? false : true;
}

Process::~Process() { }