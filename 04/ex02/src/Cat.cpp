/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 13:07:12 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

/* >----------- Cons/Destructors -----------< */
Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	announce("Cat default constructor called");
}

Cat::~Cat() {
	delete _brain;

	announce("Cat destructor called");
}

Cat::Cat(Cat const &other) : AAnimal("Cat"), _brain(new Brain()) {
	announce("Cat copy constructor called");
	_type = other.getType();
	*_brain = *other._brain;
}

Cat &Cat::operator=(Cat const &other) {
	announce("Cat copy assignment constructor called");
	_type = other.getType();

	*_brain = *other._brain;
	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	Cat::getType() const {
	return _type;
}

void Cat::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void Cat::makeSound() const {
	announce("Miaouu");
}
/* <----------------------------> */
