/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:18 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:41:19 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : type ("Animal") {
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal (Animal const &obj) {
	this->type = obj.getType();
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator= (Animal const& obj) {
	this->type = obj.getType();
	std::cout << "Animal copy assignment operator called." << std::endl;
	return *this;
}

Animal::~Animal () {
	std::cout << "Animal destructor called." << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Kawkaw, I'm an Animal." << std::endl;
}

std::string	Animal::getType() const {
	return type;
}