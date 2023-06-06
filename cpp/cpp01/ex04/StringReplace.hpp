#ifndef STRINGREPLACE_HPP
#define STRINGREPLACE_HPP

#include <string>

class StringReplace {
public :
	StringReplace(std::string, std::string);
	~StringReplace();
	std::string	replaceStringsInLine(std::string);
private :
	std::string	_findString;
	std::string _replaceString;
};

#endif // STRINGREPLACE_HPP
