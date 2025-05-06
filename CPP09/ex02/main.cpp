#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no arguments provided." << std::endl;
		return 1;
	}
	try {
		PmergeMe pmerge;
		pmerge.process(ac, av);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}