#include "InputFile.hpp"
#include <fstream>
#include <iostream>
#include <string>

InputFile::InputFile(std::string filename)
{
	mInputFile.open(filename);
}

InputFile::~InputFile()
{
}

std::string	InputFile::getlineFromInputFile()
{
	std::string	lineFromFile;

	getline(mInputFile, lineFromFile);
	if (!mInputFile.eof())
		lineFromFile += '\n';
	return lineFromFile;
}

bool	InputFile::does_file_exists()
{
	return (mInputFile.is_open());
}

bool	InputFile::checkEOF()
{
	return mInputFile.eof();
}
