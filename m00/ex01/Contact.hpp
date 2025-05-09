#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

// NOTE: Make everything private, add accesors
class Contact {
private:
	int			_id;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_number;
	std::string	_darksetSecret;
public:
	int			getId();
	void		setId(int id);
	std::string	getFirstName();
	void		setFirstName(std::string firstName);
	std::string	getLastName();
	void		setLastName(std::string lastName);
	std::string	getNickName();
	void		setNickName(std::string nickName);
	std::string	getNumber();
	void		setNumber(std::string number);
	std::string	getDarkestSecret();
	void		setDarkestSecret(std::string darksetSecret);
};
