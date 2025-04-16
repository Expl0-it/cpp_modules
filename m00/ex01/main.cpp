#include "PhoneBook.hpp"

int main (void) {
	std::string	cmd;
	PhoneBook phonebook;

	while (true) {
	
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);

		if ("ADD" == cmd)
			phonebook.add();
		else if ("SEARCH" == cmd)
			phonebook.search();
		else if ("EXIT" == cmd)
			break ;
		else if (std::cin.eof()){
			std::cout << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command" << std::endl;
		cmd.clear();
		std::cin.clear();
	}
	return 0;
}
