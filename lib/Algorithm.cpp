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

void Algorithm::WriteToCSV()
{
    // File format mentioned below for writing
    /*
        name, numberoftestcases, avgTAT, avgWT, nCS
        RR, 2, 3.23, 4.24, 5

    */

    std::cout << std::endl;
    std::cout << "Writing to File " << OUTPUT_FILE_PATH << std::endl;

    std::fstream outputFileToCheck;
    outputFileToCheck.open(OUTPUT_FILE_PATH, std::ios_base::in);

    int count = 0;
    std::string currentLine;
    while (std::getline(outputFileToCheck, currentLine)) {
        std::cout << currentLine << std::endl;
        count++;
        break;
    }

    outputFileToCheck.close();

    std::fstream outputFile;
    outputFile.open(OUTPUT_FILE_PATH, std::ios_base::app);
    if (!outputFile) {
        std::cout << "Error Writing to File " << std::endl;
    }

    if (!count) {
        // Empty File
        outputFile << "name, #cases, avgTAT, avgWT, nCS";
    } 

    std::string resultToAppend = 
        "\n" +
        this->name + "," + 
        std::to_string(this->processesToExecute->size()) + "," +
        std::to_string(this->avgTAT) + "," +
        std::to_string(this->avgWT) + "," +
        std::to_string(this->nCS);

    outputFile << resultToAppend;

}

Algorithm::~Algorithm() {
    // delete processesToExecute;
}