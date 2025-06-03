#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data 		data;
	Data 		*otherData;
	uintptr_t	ptr;

	data.topsecret = 2137;

	ptr = Serializer::serialize(&data);
	otherData = Serializer::deserialize(ptr);
	std::cout << otherData->topsecret << std::endl;
}
