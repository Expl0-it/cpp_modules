#pragma once
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_contactCount;

		void	_printContact(int id) const;
		void	_moveContacts();
		void	_printAll() const;
		void	_printDetails(int id) const;
		void	_getInput(std::string output, std::string *input);
		void	_noEmptyInput(std::string output, std::string *input);

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
};
