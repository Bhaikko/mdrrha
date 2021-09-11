#pragma once

#include "./Algorithm.h"

class SJF : public Algorithm
{
private:
    int quantum;

public:
    SJF(std::vector<Process> *processesToExecute, int quantum);

    virtual void RunAlgo() override;

    ~SJF();
};