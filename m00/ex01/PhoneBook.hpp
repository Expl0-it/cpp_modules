#pragma once
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_contactCount;
		void	printContact(int id);
		void	moveContacts();
		void	printAll();
		void	printDetails(int id);
		void	getInput(std::string output, std::string *input);

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
};
