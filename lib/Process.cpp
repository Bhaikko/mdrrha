#include "./../include/Process.h"

Process::Process(int p_id, int arrivalTime, int burstTime)
{
    this->p_id = p_id;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->completionTime = (2 ^ 32) - 1;
}
// Process::Process(Process &p)
// {
//     this->p_id = p.p_id;
//     this->arrivalTime = p.arrivalTime;
//     this->burstTime = p.burstTime;
//     this->completionTime = (2 ^ 32) - 1;
// }

bool Process::Execute(int executionTime)
{
    burstTime -= executionTime;

    return burstTime > 0 ? false : true;
}

Process::~Process() {}