/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:12 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:51:17 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class 	Animal {
public :
	Animal ();
	Animal (Animal const &);
	Animal& operator= (Animal const &);
	virtual ~Animal ();

	virtual void	makeSound() const;
	std::string		getType() const;
	
protected :
	std::string	type;
};

#endif 		// ANIMAL_HPP
