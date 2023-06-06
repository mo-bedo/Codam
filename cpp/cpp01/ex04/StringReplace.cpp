#include "StringReplace.hpp"

StringReplace::StringReplace(std::string s1, std::string s2)
{
	this->_findString = s1;
	this->_replaceString = s2;
}

StringReplace::~StringReplace()
{
}

std::string	StringReplace::replaceStringsInLine(std::string inputLine)
{
	size_t	positionOfs1 = inputLine.find(this->_findString);
	size_t	length_of_replace = this->_replaceString.length();

	if (this->_findString.empty())
		return (inputLine);
	while (positionOfs1 != std::string::npos)
	{
		inputLine.erase(positionOfs1, this->_findString.length());
		inputLine.insert(positionOfs1, this->_replaceString);
		positionOfs1 = inputLine.find(this->_findString, positionOfs1 + length_of_replace);
	}
	return (inputLine);
}
