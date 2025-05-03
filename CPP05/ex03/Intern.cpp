#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &copy) {
    (void)copy;
}
Intern &Intern::operator=(const Intern &copy) {
    (void)copy;
    return *this;
}
Intern::~Intern() {}

static AForm* makeShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}
static AForm* makeRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}
static AForm* makePresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	typedef AForm* (*FormCreator)(const std::string&);
	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormCreator creators[] = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};
	for (int i = 0; i < 3; ++i) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cerr << "Intern: unknown form names " << formName << std::endl;
	return NULL;
}