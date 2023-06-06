/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:49 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:41:50 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog (Dog const &obj) : Animal (obj) {
	this->type = obj.getType();
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator= (Dog const& obj) {
	this->type = obj.getType();
	std::cout << "Dog copy assignment operator called." << std::endl;
	return *this;
}

Dog::~Dog () {
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woefwoef, I'm a Dog." << std::endl;
}
