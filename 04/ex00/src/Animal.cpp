/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 11:43:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

/* >----------- Cons/Destructors -----------< */
Animal::Animal() : _type("Animal") {
	announce("Animal default constructor called");
}

Animal::Animal(std::string type) : _type(type) {
	announce("Animal name constructor called");
}

Animal::~Animal() {
	announce("Animal destructor called");
}

Animal::Animal(Animal const &other) : _type(other.getType()) {
	announce("Animal copy constructor called");
}

Animal &Animal::operator=(Animal const &other) {
	_type = other.getType();
	announce("Animal copy assignment constructor called");
	return *this;
}
/* <----------------------------> */



/* >----------- Get/Set -----------< */
std::string	Animal::getType() const {
	return _type;
}

void Animal::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void Animal::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void Animal::makeSound() const {
	announce("Grrrrr");
}
/* <----------------------------> */
