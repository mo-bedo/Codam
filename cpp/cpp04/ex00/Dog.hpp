/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:52 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:41:53 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
public :
	Dog ();
	Dog (const Dog&);
	Dog& operator= (const Dog&);
	~Dog ();

	 void	makeSound() const;
};

#endif		// DOG_HPP
