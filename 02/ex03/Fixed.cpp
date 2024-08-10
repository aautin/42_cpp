/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:01 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 07:35:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <string>

#include "Fixed.hpp"

/* OCCF */
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(Fixed const &operand)
{
	// std::cout << "Copy constructor called" << std::endl;

	*this = operand;
}


/* Constructors */
Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBitsNb;
}
Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;

	int		integerPart = (int)(value);
	float	fractionalPart = value - integerPart;

	this->value = (integerPart << fractionalBitsNb) + roundf(fractionalPart * (1 << fractionalBitsNb));
}


/* Others */
int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;

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
Fixed	&Fixed::min(Fixed &it1, Fixed &it2)
{
	return (it1 < it2) ? it1 : it2;
}
Fixed const	&Fixed::min(Fixed const &it1, Fixed const &it2)
{
	Fixed	it1_copy( it1 ), it2_copy( it2 );

	return (it1_copy < it2_copy) ? it1 : it2;
}
Fixed	&Fixed::max(Fixed &it1, Fixed &it2)
{
	return (it1 > it2) ? it1 : it2;
}
Fixed const	&Fixed::max(Fixed const &it1, Fixed const &it2) 
{
	Fixed	it1_copy( it1 ), it2_copy( it2 );

	return (it1_copy > it2_copy) ? it1 : it2;
}
