#include "./../include/Algorithm.h"

Algorithm::Algorithm(std::vector<Process>* processesToExecute)
{
    this->filenameToWrite = "results.csv";
    this->avgTAT = 0.0f;
    this->avgWT = 0.0f;
    this->nCS = 0;
    this->processesToExecute = processesToExecute;
}

void Algorithm::RunAlgo() {
    std::cout << name << " Started for " << this->processesToExecute->size() << " processes." << std::endl;

}

void Algorithm::WriteToCSV()
{
    std::cout << "Writing to File " << filenameToWrite << std::endl;
    // Fill This
    // Writemode should be Append NOT Overwrite
    // Look CSV format for more info
    // File format mentioned below
    /*
        name, numberoftestcases, avgTAT, avgWT, nCS
        RR, 2, 3.23, 4.24, 5

    */
}

Algorithm::~Algorithm() {
    // delete processesToExecute;
}