/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:51:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 11:43:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

/* >----------- Cons/Destructors -----------< */
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	announce("WrongCat default constructor called");
}

WrongCat::~WrongCat() {
	announce("WrongCat destructor called");
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal("WrongCat") {
	_type = other.getType();
	announce("WrongCat copy constructor called");
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
	_type = other.getType();
	announce("WrongCat copy assignment constructor called");
	return *this;
}
/* <----------------------------> */


/* >----------- Get/Set -----------< */
std::string	WrongCat::getType() const {
	return _type;
}

void WrongCat::setType(std::string newType) {
	_type = newType;
}
/* <----------------------------> */


/* >----------- Announcers -----------< */
void WrongCat::announce(std::string content) const {
	std::cout << _type << ": " << content << std::endl;
}

void WrongCat::makeSound() const {
	announce("Miaouu");
}
/* <----------------------------> */
