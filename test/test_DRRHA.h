#pragma once

#include <queue>
#include "./../include/Algorithm.h"


class test_DRRHA : public Algorithm
{
private:
    float quantum;

public:
    test_DRRHA(std::vector<Process> processesToExecute);

    virtual void RunAlgo() override;

    // ~DRRHA();
};