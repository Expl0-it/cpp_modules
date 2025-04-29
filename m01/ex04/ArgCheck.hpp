#pragma once

#ifndef ARGCHECK_HPP
# define ARGCHECK_HPP

# include <iostream>

class	ArgCheck{
private:
	ArgCheck();
	~ArgCheck();

public:
	static bool	checkArgCount(int argc, int expected);
};

#endif // !ARGCHECK_HPP
