#include "./../include/Algorithm.h"

Algorithm::Algorithm(std::vector<Process>* processesToExecute)
{
    this->avgTAT = 0.0f;
    this->avgWT = 0.0f;
    this->nCS = 0;
    this->processesToExecute = processesToExecute;
}

void Algorithm::RunAlgo() {
    std::cout << name + " Started for " + std::to_string(this->processesToExecute->size()) + " processes." << std::endl;

}

Algorithm::~Algorithm() {
    // delete processesToExecute;
}