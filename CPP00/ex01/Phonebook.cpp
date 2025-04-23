#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : _contactCount(0), _OldestIndex(0) {}
Phonebook::~Phonebook() {}

void Phonebook::addContact() {
	Contact newContact;
	newContact.setContact();
	
	if (newContact.isEmpty()) {
		std::cout << "Contact not saved: needed all fields to be filled" << std::endl;
		return;
	}
	_contact[_OldestIndex] = newContact;
	if (_contactCount < 8)
		_contactCount++;
	_OldestIndex = (_OldestIndex + 1) % 8;
	std::cout << "Contact saved with Success" << std::endl;
}

void Phonebook::searchContact() const {
	if (_contactCount == 0) {
		std::cout << "No available contacts" << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name|  Last Name|  NickName|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _contactCount; i++) {
		_contact[i].ShowBrief(i);
	}
	std::cout << "Enter the index of the contact to view: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || !isdigit(input[0])) {
		std::cout << "Invalid input" << std ::endl;
		return;
	}

	int index = input[0] - '0';
	if (index < 0 || index >=_contactCount) {
		std::cout << "Index out of range." << std::endl;
		return;
	}
	std::cout << std::endl;
	_contact[index].showFull();
	std::cout << std::endl;
}
