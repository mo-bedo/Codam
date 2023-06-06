#include "InputFile.hpp"
#include "NewFile.hpp"
#include "StringReplace.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number or arguments; program only takes 3 (no more, no less). Exiting program." << std::endl;
		return 1;
	}
	InputFile		infile(argv[1]);
	NewFile 		outfile(argv[1]);
	StringReplace	replacer(argv[2], argv[3]);
	std::string 	inputLine, outputLine;

	if (!infile.does_file_exists())
	{
		std::cout << argv[1] << " not found. Exiting program." << std::endl;
		return 1;
	}
	while(!infile.checkEOF())
	{
		inputLine = infile.getlineFromInputFile();
		outputLine = replacer.replaceStringsInLine(inputLine);
		outfile.writeLineToFile(outputLine);
	}
	return 0;
}
