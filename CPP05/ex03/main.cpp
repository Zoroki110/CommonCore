#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n=== TEST 1: shrubbery creation ===" << std::endl;
    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    std::cout << "\n=== TEST 2: robotomy request ===" << std::endl;
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    std::cout << "\n=== TEST 3: presidential pardon ===" << std::endl;
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Rick");
    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    std::cout << "\n=== TEST 4: formulaire inconnu ===" << std::endl;
    AForm* form4 = someRandomIntern.makeForm("death note", "Light Yagami");
    if (!form4)
        std::cout << "Échec attendu : formulaire non reconnu\n";

    return 0;
}
