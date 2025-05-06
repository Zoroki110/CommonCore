#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: expected one argument." << std::endl;
        return 1;
    }

    RPN rpn;
    int result = rpn.calculate(av[1]);
    std::cout << result << std::endl;

    return 0;
}