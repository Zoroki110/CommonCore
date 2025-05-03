#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== TEST 1: Bureaucrat valide ===" << std::endl;
    try {
        Bureaucrat jean("Jean", 2);
        std::cout << jean << std::endl;

        std::cout << "→ On incrémente le grade de Jean" << std::endl;
        jean.incrementGrade();
        std::cout << jean << std::endl;

        std::cout << "→ On tente encore une fois (devrait échouer)" << std::endl;
        jean.incrementGrade(); // Exception attendue
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Bureaucrat avec grade trop bas ===" << std::endl;
    try {
        Bureaucrat paul("Paul", 151); // Exception attendue
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Bureaucrat avec grade trop haut ===" << std::endl;
    try {
        Bureaucrat anna("Anna", 0); // Exception attendue
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Decrement jusqu'à exception ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 149);
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade(); // Exception attendue
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
