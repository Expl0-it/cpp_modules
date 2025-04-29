#include "ArgCheck.hpp"
#include "Sed.hpp"

int main (int argc, char *argv[]) {

	if (false == ArgCheck::checkArgCount(argc, 4))
		return (1);

	Sed	sed(argv[1], argv[2], argv[3]);
	if (false == sed.filesOpened())
		return (1);

	if (false == sed.writeFile())
		return (1);

	return 0;
}
