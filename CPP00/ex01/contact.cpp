#include <iostream>
#include <iomanip>
#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setContact() {
	std::string input;

	std::cout << "Enter first Name: ";
	std::getline(std::cin, _firstName);
	if (_firstName.empty()) return;

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, _lastName);
	if (_lastName.empty()) return;

	std::cout << "Enter NickName: ";
	std::getline(std::cin, _nickName);
	if (_nickName.empty()) return;

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, _phoneNumber);
	if (_phoneNumber.empty()) return;

	std::cout << "Enter Darkest Secret :";
	std::getline(std::cin, _darkestSecret);
	if (_darkestSecret.empty()) return ;
}

bool Contact::isEmpty() const {
	return _firstName.empty() && _lastName.empty() && _nickName.empty() && _phoneNumber.empty() && _darkestSecret.empty();
}

static std::string truncate(const std::string& str){
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::ShowBrief(int index) const {
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << truncate(_firstName);
	std::cout << "|" << std::setw(10) << truncate(_lastName);
	std::cout << "|" << std::setw(10) << truncate(_nickName);
	std::cout << "|" << std::endl;
}

void Contact::showFull() const {
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "NickName: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
 }