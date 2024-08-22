/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 11:43:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

/* >----------- Cons/Destructors -----------< */
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	announce("WrongAnimal default constructor called");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	announce("WrongAnimal name constructor called");
}

WrongAnimal::~WrongAnimal() {
	announce("WrongAnimal destructor called");
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other.getType()) {
	announce("WrongAnimal copy constructor called");
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	_type = other.getType();
	announce("WrongAnimal copy assignment constructor called");
	return *this;
}
/* <----------------------------> */



/* >----------- Get/Set -----------< */
std::string	WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void WrongAnimal::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void WrongAnimal::makeSound() const {
	announce("Grrrrr");
}
/* <----------------------------> */
