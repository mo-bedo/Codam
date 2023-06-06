#include <iostream>

int	main(int argc, char **argv)
{
	char c;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j]; j++)
			{
				c = toupper(argv[i][j]);
				std::cout << c;
			}
	std::cout << std::endl;
	return 0;
}
