#include "Array.hpp"
#include "Array.inc.hpp"

int main()
{	
{
	Array<int> empty_ints;
	std::cout << "ints size: " << empty_ints.size() << std::endl;

	try
	{
		empty_ints[5] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<int> ints(5);
	std::cout << "ints size: " << ints.size() << std::endl;
	std::cout << "ints 0 = " << ints[0] << std::endl;

	try
	{
		ints[0] = 5;
		ints[5] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < 5; i++)
		ints[i] = i + 1;
		
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "ints[" << i << "]: " << ints[i] << std::endl;
		total += ints[i];
	}
	std::cout << "total: " << total << std::endl;
	
	Array<std::string> strings(3);
	strings[1] = "abc";
	std::cout << "strings[1] = " << strings[1] << std::endl;

	Array<int> copy(ints);
	for (int i = 0; i < 5; i++)
		std::cout << "ints[" << i << "]: " << copy[i] << std::endl;

	const Array<int> copy2 = copy;
	for (int i = 0; i < 5; i++)
		std::cout << "ints[" << i << "]: " << copy2[i] << std::endl;
}
{
	Array<char> chars(5);
	for (unsigned int i = 0; i < 5; i++)
		chars[i] = 'a' + i;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << "chars[" << i << "]: " << chars[i] << std::endl;
}
}
