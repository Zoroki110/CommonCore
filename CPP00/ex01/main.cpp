#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main() {
	Phonebook phonebook;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook! 📞" << std::endl;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof()) {
			std::cout << "Exiting Phonebook. Goodbye! 👋" << std::endl;
			break;
		}
		if (command == "ADD" || command == "add") {
			phonebook.addContact();
		}
		else if (command == "SEARCH" || command == "search") {
			phonebook.searchContact();
		}
		else if (command == "EXIT" || command == "exit") {
			std::cout << "Exiting Phonebook. Goodbye! 👋" << std::endl;
			break;
		}
		else {
			std::cout << "Unknow command. Try again." << std::endl;
		}
	}
	return 0;
}