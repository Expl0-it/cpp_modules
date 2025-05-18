#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

#include <iostream>

class Megaphone{
	private:
		Megaphone();
		~Megaphone();
	public:
		static void	capitalize(int argc, char **argv);
};

#endif // !MEGAPHONE_HPP
