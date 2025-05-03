#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;

	public :
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& f);
		void executeForm(AForm const& form);

		class GradeTooHighException : public std::exception {
				public :
					const char* what() const throw();
		};
		class GradeTooLowExcpetion : public std::exception {
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat & bureaucrat);

#endif