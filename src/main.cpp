#include <iostream>

#include "./../include/Process.h"

int main()
{
    Process process(1, 10, 5);

    std::cout << process.Execute(2) << std::endl;   // Should Print 0
    std::cout << process.Execute(2) << std::endl;   // Should Print 0
    std::cout << process.Execute(2) << std::endl;   // Should Print 1

    return 0;
}