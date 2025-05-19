#include "Brain.hpp"

Brain::Brain() {
	_createIdeas("Random Idea");
	std::cout << "Brain Created" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(Brain const& src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator=(Brain const& src) {
	std::cout << "Brain assigment operator called" << std::endl;
	if (this != &src) {
		this->_copyIdeas(src._ideas);
	}
	return (*this);
}

void	Brain::_createIdeas(std::string text) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = text;
}

void	Brain::_copyIdeas(const std::string ideas[]) {
	for (size_t i = 0; i < ideas->length(); i++)
		this->_ideas[i] = ideas[i];
}

std::string	Brain::getIdea(unsigned int index) const {
	if (index >= 100) {
		std::cout << "Invalid index, there is only 100 ideas" << std::endl;
		return ("");
	}
	return (_ideas[index]);
}
