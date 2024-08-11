/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOverloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:01 by aautin            #+#    #+#             */
/*   Updated: 2024/08/11 16:56:56 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <string>

#include "Fixed.hpp"

/* Private */
Fixed	&Fixed::operator=(Fixed const &operand)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &operand)
		this->value = operand.getRawBits();

	return *this;
}
Fixed	Fixed::operator+(Fixed const &operand)
{
	Fixed res(this->toFloat() + operand.toFloat());
	return res;
}
Fixed	Fixed::operator-(Fixed const &operand)
{
	Fixed res(this->toFloat() - operand.toFloat());
	return res;
}
Fixed	Fixed::operator*(Fixed const &operand)
{
	Fixed res(this->toFloat() * operand.toFloat());
	return res;
}
Fixed	Fixed::operator/(Fixed const &operand)
{
	Fixed res(this->toFloat() / operand.toFloat());
	return res;
}
bool	Fixed::operator<(Fixed const &operand)  { return toFloat() < operand.toFloat();  }
bool	Fixed::operator<=(Fixed const &operand) { return toFloat() <= operand.toFloat(); }
bool	Fixed::operator>(Fixed const &operand)  { return toFloat() > operand.toFloat();  }
bool	Fixed::operator>=(Fixed const &operand) { return toFloat() >= operand.toFloat(); }
bool	Fixed::operator==(Fixed const &operand) { return toFloat() > operand.toFloat();  }
bool	Fixed::operator!=(Fixed const &operand) { return toFloat() != operand.toFloat(); }
float	Fixed::operator++(int)
{
	float	previousValue = toFloat();

	/* if no-overflow-possible */
	if ((value & ((1 << (fractionalBitsNb + 1)) - 1)) != (1 << (fractionalBitsNb + 1)) - 2)
		value += 1;
	else {
		int	integerPart = value >> fractionalBitsNb;
		value = 0;
		value += (integerPart + 1) >> fractionalBitsNb;
	}

	return previousValue;
}
float	Fixed::operator--(int)
{
	float	previousValue = toFloat();

	/* if no-underflow-possible */
	if ((value & ((1 << (fractionalBitsNb + 1)) - 1)) != 0)
		value -= 1;
	else {
		int	integerPart = value >> fractionalBitsNb;
		value = 0;
		value += ((integerPart - 1) >> fractionalBitsNb) + ((1 << (fractionalBitsNb + 1)) - 1);
	}

	return previousValue;
}
float	Fixed::operator++()
{
	/* if no-overflow-possible */
	if ((value & ((1 << (fractionalBitsNb + 1)) - 1)) != (1 << (fractionalBitsNb + 1)) - 2)
		value += 1;
	else {
		int	integerPart = value >> fractionalBitsNb;
		value = 0;
		value += (integerPart + 1) >> fractionalBitsNb;
	}

	return toFloat();
}
float	Fixed::operator--()
{
	/* if no-underflow-possible */
	if ((value & ((1 << (fractionalBitsNb + 1)) - 1)) != 0)
		value -= 1;
	else {
		int	integerPart = value >> fractionalBitsNb;
		value = 0;
		value += ((integerPart - 1) >> fractionalBitsNb) + ((1 << (fractionalBitsNb + 1)) - 1);
	}

	return toFloat();
}


/* Public */
std::ostream	&operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << fixed.toFloat();
	return outputStream;
}
