#include "iter.hpp"

#include <iostream>

template <typename T>
void printElement(T &element) {
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &element) {
	element++;
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    std::string strs[] = {"42", "Bruxelles", "Piscine", "C++"};

    std::cout << "Avant incrementation: " << std::endl;
    iter(tab, 5, printElement);
    std::cout << std::endl;

    iter(tab, 5, increment);

    std::cout << "Apres incrementation: "<< std::endl;
    iter(tab, 5, printElement);
    std::cout << std::endl;

    std::cout << "Affichage de strings: "<< std::endl;
    iter(strs, 4, printElement);
    std::cout << std::endl;

    return 0;
}