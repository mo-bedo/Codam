#include "NewFile.hpp"
#include <string>
#include <fstream>

NewFile::NewFile(std::string filename)
{
	filename += ".replace";

	mNewFile.open(filename);
}

NewFile::~NewFile()
{
}

void 	NewFile::writeLineToFile(std::string inputtext)
{
	mNewFile << inputtext;
}
