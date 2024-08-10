/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:01 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 03:18:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <string>

#include "Fixed.hpp"

/* OCCF */
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
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

/* Operators overloads */
Fixed			&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		/* Here, do all the assignments */
		this->value = other.getRawBits();
	}

	return *this;
}
std::ostream	&operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return outputStream;
}

/* Constructors */
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBitsNb;
}
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;

	int		integerPart = (int)(value);
	float	fractionalPart = value - integerPart;

	this->value = (integerPart << fractionalBitsNb) + roundf(fractionalPart * (1 << fractionalBitsNb));
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
int		Fixed::toInt( void ) const
{
	return this->value >> 8;
}
float	Fixed::toFloat( void ) const
{
	float	integerPart = value >> fractionalBitsNb;
	float	fractionalPart = value & ((1 << (fractionalBitsNb + 1)) - 1);

	return integerPart + (fractionalPart / (1 << fractionalBitsNb));
}
