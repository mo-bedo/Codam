#include "Harl.hpp"

int main()
{
	Harl henk;

	henk.complain("DEBUG");
	henk.complain("INFO");
	henk.complain("WARNING");
	henk.complain("ERROR");

	henk.complain("");
	henk.complain(" DEBUG");
	henk.complain(" INFO");
	henk.complain("WARNING ");
	henk.complain("ERROR ");
}
