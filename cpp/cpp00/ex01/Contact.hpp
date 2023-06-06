#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>

class Contact {
public :
	Contact();
	~Contact();
	void 		add(int);
	void		display_all() const;
	void		display_single() const;
private :
	void		clear_contact();
	void		check_input_for_tabs();
	std::string replace_tabs(std::string);
	int 		index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	phonenumber;
	std::string secret;
};

#endif	// CONTACT_CLASS_HPP
