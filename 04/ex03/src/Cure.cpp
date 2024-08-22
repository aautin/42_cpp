/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:46 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 17:22:24 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"
#include "ICharacter.hpp"

/* >----------- Cons/Destructors -----------< */
Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other.getType()) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
	std::cout << "Cure copy assignment called" << std::endl;

	_type = other.getType();
	return *this;
}
/* <----------------------------> */


/* >----------- Others -----------< */
AMateria *Cure::clone() const {
	AMateria *clone = new Cure;

	clone->_type = _type;
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() + "'s wounds *";
	std::cout << std::endl;
}
/* <----------------------------> */
