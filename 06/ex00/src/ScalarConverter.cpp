/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by aautin            #+#    #+#             */
/*   Updated: 2024/09/19 15:24:49 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

static int getType(std::string &literal) {
	if (literal.length() == 1 && isascii(literal.at(0)))
		return CHAR;

	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE_EXCEPTION;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT_EXCEPTION;

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++) {
		if (isdigit(*it) || *it == '.')
			continue;
		if (*it == 'f' && it + 1 == literal.end())
			return FLOAT;
		return NONE;
	}

	if (literal.find('.') == std::string::npos)
		return INT;
	if (literal.find('.') == literal.rfind('.'))
		return DOUBLE;

	return NONE;
}


/* >----------- String->Double conversion -----------< */
static void charString(std::string &literal) {
	t_scalar number = {
		literal.at(0),
		static_cast<int>(number.c),
		static_cast<float>(number.c),
		static_cast<>
	};
}
static void intString(std::string &literal) {
}
static void floatString(std::string &literal) {
}
static void doubleString(std::string &literal) {
}
/* <----------------------------> */


/* >----------- Print -----------< */
static std::string getPrecision(float input) {
	if (input == static_cast<float>(static_cast<long long>(input)))
		return ".0";
	else
		return "";
}
static void notypeExceptionPrint() {
	std::cout << "Literal incorrect." << std::endl;	
	throw ScalarConverter::Exception();
}
static void	fractionalExceptionPrint(std::string const &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
	throw ScalarConverter::Exception();
}
/* <----------------------------> */


void ScalarConverter::convert(std::string &literal) {
	void	(*stringConverters[4])(std::string &literal) = {
		&charString, &intString,
		&floatString, &doubleString
	};

	int const literalType = getType(literal);
	try {
		switch (literalType) {
			case NONE:
				notypeExceptionPrint();
			case FLOAT_EXCEPTION:
				fractionalExceptionPrint(literal.substr(0, literal.length() - 1));
			case DOUBLE_EXCEPTION:
				fractionalExceptionPrint(literal);
		}
		stringConverters[literalType](literal);
	}
	catch (...) {}
}
