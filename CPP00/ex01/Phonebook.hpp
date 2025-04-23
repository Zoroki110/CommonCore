#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
	private :
		Contact _contact[8];
		int _contactCount;
		int _OldestIndex;

	public :
		Phonebook();
		~Phonebook();

		void addContact();
		void searchContact() const;
};

#endif