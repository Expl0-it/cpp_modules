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

	if (8 == this->_contactCount){
		new_id = 7;
		_moveContacts();
	}
	else {
		new_id = this->_contactCount;
		this->_contactCount++;
	}
	this->_contacts[new_id].id = new_id;
	_noEmptyInput("Enter first name: ", &(this->_contacts[new_id].firstName));
	_noEmptyInput("Enter last name: ", &(this->_contacts[new_id].lastName));
	_noEmptyInput("Enter nickname: ", &(this->_contacts[new_id].nickname));
	_noEmptyInput("Enter number: ", &(this->_contacts[new_id].number));
	_noEmptyInput("Enter darkest secret: ", &(this->_contacts[new_id].darksetSecret));
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
		this->_contacts[i - 1].id--;
		i++;
	}
}

void	PhoneBook::_printDetails(int id) const {
	Contact ct = this->_contacts[id];

	std::cout << "Id: " << ct.id << std::endl;
	std::cout << "First Name: " << ct.firstName << std::endl;
	std::cout << "Last Name: " << ct.lastName << std::endl;
	std::cout << "Nickname: " << ct.nickname << std::endl;
	std::cout << "Number: " << ct.number << std::endl;
	std::cout << "Darkest Secret: " << ct.darksetSecret << std::endl;
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
	
	std::cout << std::right << std::setw(10) << ct.id << " | ";
	
	if (ct.firstName.length() > 10)
		std::cout << " " << std::right << ct.firstName.substr(0, 9) << "." << " | ";
	else
		std::cout << " " << std::right << std::setw(10) << ct.firstName << " | ";

	if (ct.lastName.length() > 10)
		std::cout << std::right << std::setw(10) << ct.lastName.substr(0 , 9) << "." << " | ";
	else
		std::cout << " " << std::right << std::setw(10) << ct.lastName << " | ";
	
	if (ct.nickname.length() > 10)
		std::cout << std::right << std::setw(10) << ct.nickname.substr(0 , 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << ct.nickname << " |";

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
	while (NULL == input || "" == *input /*|| "\n" == *input*/){
		std::cout << "Provide valid input" << std::endl;
		_getInput(output, input);
	}
}
