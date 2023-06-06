#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact()
{
	this->index = -1;
}

Contact::~Contact()
{
}

void	Contact::clear_contact()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phonenumber.clear();
	this->secret.clear();
}

std::string	Contact::replace_tabs(std::string input)
{
	size_t	posOfTab = input.find('\t');

	while (posOfTab != std::string::npos)
	{
		input.erase(posOfTab, 1);
		input.insert(posOfTab, "    ");
		posOfTab = input.find('\t');
	}
	return input;
}

void		Contact::check_input_for_tabs()
{
	this->first_name = replace_tabs(first_name);
	this->last_name = replace_tabs(last_name);
	this->nickname = replace_tabs(nickname);
}

static std::string	getline_wrap()
{
	std::string	get_line;

	getline(std::cin, get_line, '\n');
	if (std::cin.eof())
	{
		std::cout << std::endl << "Exiting" << std::endl;
		exit(1);
	}
	return get_line;
}

void	Contact::add(int ind)
{
	if (index == ind)
		clear_contact();
	index = ind;
	std::cout << "Please input your info (no empty input; program will wait for non-empty input)" << std::endl;
	std::cout << "First name: ";
	while (first_name.empty())
		first_name = getline_wrap();
	std::cout << "Last name: ";
	while (last_name.empty())
		last_name = getline_wrap();
	std::cout << "Nickname: ";
	while (nickname.empty())
		nickname = getline_wrap();
	std::cout << "Phone number: ";
	while(phonenumber.empty())
		phonenumber = getline_wrap();
	std::cout << "Your darkest secret: ";
	while (secret.empty())
		secret = getline_wrap();
	check_input_for_tabs();
}

void	Contact::display_all() const
{
	if (index != -1)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << index;
		std::cout << '|';
		if (first_name.size() < 11)
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << first_name;
		}
		else
			std::cout << first_name.substr(0,9) << '.';
		std::cout << '|';
		if (last_name.size() < 11)
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << last_name;
		}
		else
			std::cout << last_name.substr(0,9) << '.';
		std::cout << '|';
		if (nickname.size() < 11)
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << nickname;
		}
		else
			std::cout << nickname.substr(0, 9) << '.';
		std::cout << std::endl;
	}
}

void	Contact::display_single() const
{
	if (this->index == -1)
	{
		std::cout << "No contact found." << std::endl;
		return ;
	}
	std::cout << "Index:\t\t " << this->index << std::endl;
	std::cout << "First name:\t " << this->first_name << std::endl;
	std::cout << "Last name:\t " << this->last_name << std::endl;
	std::cout << "Nickname:\t " << this->nickname << std::endl;
	std::cout << "Phone number:\t " << this->phonenumber << std::endl;
	std::cout << "Darkest secret:\t " << this->secret << std::endl;
}
