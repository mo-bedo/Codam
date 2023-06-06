#ifndef INPUTFILE_HPP
#define INPUTFILE_HPP

#include <string>
#include <fstream>

class InputFile {
public :
	InputFile(std::string);
	~InputFile();
	std::string	getlineFromInputFile();
	bool		checkEOF();
	bool		does_file_exists();
private :
	std::ifstream	mInputFile;
};

#endif 	// INPUTFILE_HPP
