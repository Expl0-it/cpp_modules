#include "Contact.hpp"

int			Contact::getId(){
	return (this->_id);
}
void		Contact::setId(int id){
	this->_id = id;
}
std::string	Contact::getFirstName(){
	return (this->_firstName);
}
void		Contact::setFirstName(std::string firstName){
	this->_firstName = firstName;
}
std::string	Contact::getLastName(){
	return (this->_lastName);
}
void		Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}
std::string	Contact::getNickName(){
	return (this->_nickname);
}
void		Contact::setNickName(std::string nickName){
	this->_nickname = nickName;
}
std::string	Contact::getNumber(){
	return (this->_number);
}
void		Contact::setNumber(std::string number){
	this->_number = number;
}
std::string	Contact::getDarkestSecret(){
	return (this->_darksetSecret);
}
void		Contact::setDarkestSecret(std::string darkestSecret){
	this->_darksetSecret = darkestSecret;
}
