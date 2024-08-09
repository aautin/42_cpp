/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:01 by aautin            #+#    #+#             */
/*   Updated: 2024/08/09 15:38:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Fixed.hpp"

/* OCCF */
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}
Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		/* Here, do all the assignments */
		this->value = other.getRawBits();
	}

	return *this;
}


/* Others */
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->value;
}
void	Fixed::setRawBits( int const raw )
{
	value = raw;
}
