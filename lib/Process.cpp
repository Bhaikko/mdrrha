#include "./../include/Process.h"

Process::Process(int p_id, int arrivalTime, int burstTime)
{
    this->p_id = p_id;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->originalBT = burstTime;
    this->completionTime = (2 ^ 32) - 1;
    this->responseTime = -1;
    this->responseRatio = 0;
}

bool Process::Execute(int executionTime, int currentTime)
{
    burstTime -= executionTime;

    if (this->responseTime == -1) {
        this->responseTime = currentTime;
    }

    return burstTime > 0 ? false : true;
}

Process::~Process() {}