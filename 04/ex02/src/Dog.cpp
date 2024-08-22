/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 13:07:09 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

/* >----------- Cons/Destructors -----------< */
Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	announce("Dog default constructor called");
}

Dog::~Dog() {
	delete _brain;

	announce("Dog destructor called");
}

Dog::Dog(Dog const &other) : AAnimal("Dog"), _brain(new Brain()) {
	announce("Dog copy constructor called");
	_type = other.getType();
	*_brain = *other._brain;
}

Dog &Dog::operator=(Dog const &other) {
	announce("Dog copy assignment constructor called");
	_type = other.getType();

	*_brain = *other._brain;
	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	Dog::getType() const {
	return _type;
}

void Dog::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void Dog::makeSound() const {
	announce("Wouaff");
}
/* <----------------------------> */
