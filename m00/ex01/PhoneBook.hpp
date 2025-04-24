#pragma once
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_contactCount;
		void	printContact(int id) const;
		void	moveContacts();
		void	printAll() const;
		void	printDetails(int id) const;
		void	getInput(std::string output, std::string *input);
		void	noEmptyInput(std::string output, std::string *input);

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
};
