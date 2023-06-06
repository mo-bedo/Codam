/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:43 by jbedaux           #+#    #+#             */
/*   Updated: 2022/10/24 16:41:44 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal {
public :
	Cat ();
	Cat (const Cat&);
	Cat& operator= (Cat const&);
	~Cat ();

	void	makeSound() const;
};

#endif 		// CAT_HPP
