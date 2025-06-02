#pragma once
#include <iostream>


namespace harl_utils {
	typedef enum e_level{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
}				t_level;
};

namespace hu = harl_utils;

class Harl {

public:
	Harl();
	~Harl();

	void	complain(std::string level);

private:
	hu::t_level	assignEnum(std::string level);
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
};
