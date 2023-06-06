#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	henk;

	if (argc != 2)
		henk.complain("");
	else
		henk.complain(argv[1]);
}
