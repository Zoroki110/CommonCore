#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
protected :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public : 
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);

	virtual void execute(Bureaucrat const& executor) const = 0;

	class NotSignedException : public std::exception {
		public :
			const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
		public :
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public :
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif