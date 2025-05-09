#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	_contactCount = 0;
	std::cout << "PhoneBook Created" << std::endl;
}

PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook Destroyed" << std::endl;
}

void	PhoneBook::add(){
	int	new_id;
	std::string temp;

	if (8 == this->_contactCount){
		new_id = 7;
		_moveContacts();
	}
	else {
		new_id = this->_contactCount;
		this->_contactCount++;
	}
	this->_contacts[new_id].setId(new_id);
	_noEmptyInput("Enter first name: ", &temp);
	this->_contacts[new_id].setFirstName(temp);
	_noEmptyInput("Enter last name: ", &temp);
	this->_contacts[new_id].setLastName(temp);
	_noEmptyInput("Enter nickname: ", &temp);
	this->_contacts[new_id].setNickName(temp);
	_noEmptyInput("Enter number: ", &temp);
	this->_contacts[new_id].setNumber(temp);
	_noEmptyInput("Enter darkest secret: ", &temp);
	this->_contacts[new_id].setDarkestSecret(temp);
}

void	PhoneBook::search(){
	int					c_id;
	std::string 		id;
	std::stringstream	ss;

	_printAll();

	_getInput("Enter contact index: ", &id);
	ss.clear();
	if (false == std::isdigit(id[0])){
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	ss.str(id);
	ss >> c_id;

	if (c_id < 0 || c_id > this->_contactCount - 1){
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	else
		_printDetails(c_id);
}

void	PhoneBook::_moveContacts(){
	int	i = 1;

	while (i < 8) {
		this->_contacts[i - 1] = this->_contacts[i];
		this->_contacts[i - 1].setId(i - 1);
		i++;
	}
}

void	PhoneBook::_printDetails(int id) const {
	Contact ct = this->_contacts[id];

	std::cout << "Id: " << ct.getId() << std::endl;
	std::cout << "First Name: " << ct.getFirstName() << std::endl;
	std::cout << "Last Name: " << ct.getLastName() << std::endl;
	std::cout << "Nickname: " << ct.getNickName() << std::endl;
	std::cout << "Number: " << ct.getNumber() << std::endl;
	std::cout << "Darkest Secret: " << ct.getDarkestSecret() << std::endl;
}

void	PhoneBook::_printAll() const {
	int	i = 0;

	while (i < this->_contactCount) {
		_printContact(i);
		i++;
	}
}

void	PhoneBook::_printContact(int id) const {
	Contact	ct = this->_contacts[id];
	
	std::cout << std::right << std::setw(10) << ct.getId() << " | ";
	
	if (ct.getFirstName().length() > 10)
		std::cout << " " << std::right << ct.getFirstName().substr(0, 9) << "." << " | ";
	else
		std::cout << " " << std::right << std::setw(10) << ct.getFirstName() << " | ";

	if (ct.getLastName().length() > 10)
		std::cout << std::right << std::setw(10) << ct.getLastName().substr(0 , 9) << "." << " | ";
	else
		std::cout << " " << std::right << std::setw(10) << ct.getLastName() << " | ";
	
	if (ct.getNickName().length() > 10)
		std::cout << std::right << std::setw(10) << ct.getNickName().substr(0 , 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << ct.getNickName() << " |";

	std::cout << std::endl;
}

void	PhoneBook::_getInput(std::string output, std::string *input){
	*input = "";
	while (*input == "" && !std::cin.eof()) {
		std::cout << output;
		if (std::getline(std::cin, *input))
			break ;
		else
			std::cout << "Provide Input" << std::endl;
	}
}

void	PhoneBook::_noEmptyInput(std::string output, std::string *input){
	_getInput(output, input);
	while (NULL == input || "" == *input /*|| "\n" == *input*/) {
		if (std::cin.eof())
			break ;
		std::cout << "Provide valid input" << std::endl;
		_getInput(output, input);
	}
}
