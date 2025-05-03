#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat alice("Alice", 1);        // peut tout signer et exécuter
    Bureaucrat bob("Bob", 140);          // peut juste signer des shrubbery
    Bureaucrat jean("Jean", 150);        // ne peut rien faire

    ShrubberyCreationForm tree("arbre");
    RobotomyRequestForm robot("wall-e");
    PresidentialPardonForm pardon("Macron");

    std::cout << "\n=== TEST 1: shrubbery ===" << std::endl;
    bob.signForm(tree);
    bob.executeForm(tree);         // devrait échouer (exec: 137, bob = 140)
    alice.executeForm(tree);       // devrait réussir

    std::cout << "\n=== TEST 2: robotomy ===" << std::endl;
    alice.signForm(robot);
    alice.executeForm(robot);      // 50% de chance de succès

    std::cout << "\n=== TEST 3: pardon ===" << std::endl;
    alice.signForm(pardon);
    alice.executeForm(pardon);     // succès assuré

    std::cout << "\n=== TEST 4: échec de signature ===" << std::endl;
    jean.signForm(pardon);         // devrait échouer

    std::cout << "\n=== TEST 5: échec d'exécution non signée ===" << std::endl;
    PresidentialPardonForm test("Morty");
    alice.executeForm(test);       // pas signé → exception

    return 0;
}
