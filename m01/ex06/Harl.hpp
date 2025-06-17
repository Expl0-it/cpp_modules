#pragma once
#include <iostream>


namespace harl_utils {
	typedef enum e_level{
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
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
