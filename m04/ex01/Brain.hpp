#pragma once

#include <iostream>

class Brain{
public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	~Brain();

	std::string	getIdea(unsigned int index) const;

private:
	std::string	_ideas[100];

	void		_createIdeas(std::string text);
	void		_copyIdeas(const std::string ideas[]);

};
