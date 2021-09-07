#include "./../include/Algorithm.h"

Algorithm::Algorithm(std::vector<Process>* processesToExecute)
{
    this->avgTAT = 0.0f;
    this->avgWT = 0.0f;
    this->nCS = 0;
    this->processesToExecute = processesToExecute;
}

void Algorithm::RunAlgo() {
    std::cout << name << " Started for " << this->processesToExecute->size() << " processes." << std::endl;

}

void Algorithm::ProcessResult()
{
    // File format mentioned below for writing
    /*
        name, numberoftestcases, avgTAT, avgWT, nCS
        RR, 2, 3.23, 4.24, 5

    */

    std::string resultToAppend = 
        "\n" +
        this->name + "," + 
        std::to_string(this->processesToExecute->size()) + "," +
        std::to_string(this->avgTAT) + "," +
        std::to_string(this->avgWT) + "," +
        std::to_string(this->nCS);

    WriteToCSV(resultToAppend);


}

Algorithm::~Algorithm() {
    // delete processesToExecute;
}