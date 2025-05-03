#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::NotSignedException::what() const throw() {
	return "form not signed!";
}
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream &os, const AForm &f) {
	os << f.getName()
	   << " ,signed: " << (f.isSigned() ? "yes" : "no")
	   << " , grade to sign: " << f.getGradeToSign()
	   << " , grade to execute: " << f.getGradeToExecute();
	return os;
}