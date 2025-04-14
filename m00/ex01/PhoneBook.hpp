#pragma
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_contactCount;
		void	printContact(int id);
		void	moveContacts();
		void	printAll();
		void	getInput();

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
};
