#include "./../include/RoundRobin.h"

RoundRobin::RoundRobin(std::vector<Process>* processesToExecute) : Algorithm(processesToExecute)
{
    this->name = "RR";
}

void RoundRobin::RunAlgo()
{
    Algorithm::RunAlgo();

    for (unsigned int i = 0; i < processesToExecute->size(); i++) {        
        // Write Algo Here

    }

    std::cout << this->name + "Ended for " + std::to_string(processesToExecute->size()) + " processes." << std::endl;

}

RoundRobin::~RoundRobin()
{

}