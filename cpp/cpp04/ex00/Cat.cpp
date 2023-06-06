/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:38 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:41:39 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat (const Cat &obj) : Animal(obj) {
	this->type = obj.getType();
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator= (Cat const& obj) {
	this->type = obj.getType();
	std::cout << "Cat copy assignment operator called." << std::endl;
	return *this;
}

Cat::~Cat () {
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Purpur, I'm a Cat." << std::endl;
}
