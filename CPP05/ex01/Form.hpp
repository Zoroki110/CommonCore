#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
private :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public : 
	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		public :
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public :
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif