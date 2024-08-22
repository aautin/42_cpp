/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:44 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 19:25:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:46 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 17:18:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"
#include "ICharacter.hpp"

/* >----------- Cons/Destructors -----------< */
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other.getType()) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
	std::cout << "Ice copy assignment called" << std::endl;

	_type = other.getType();
	return *this;
}
/* <----------------------------> */


/* >----------- Others -----------< */
AMateria *Ice::clone() const {
	AMateria *newIce = new Ice;

	*newIce = *this;
	return newIce;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() + " *";
	std::cout << std::endl;
}
/* <----------------------------> */
