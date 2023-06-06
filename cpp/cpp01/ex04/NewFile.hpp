#ifndef NEWFILE_HPP
#define NEWFILE_HPP

#include <fstream>
#include <string>

class NewFile {
public :
	NewFile(std::string);
	~NewFile();
	void	writeLineToFile(std::string);
private :
	std::ofstream	mNewFile;
};

#endif // NEWFILE_HPP
