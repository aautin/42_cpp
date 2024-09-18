/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by aautin            #+#    #+#             */
/*   Updated: 2024/09/18 15:40:12 by aautin           ###   ########.fr       */
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
static double doubleStringToDouble(std::string &literal) {
	return std::strtod(literal.c_str(), NULL);
}
static double charStringToDouble(std::string &literal) {
	return literal.at(0);
}
static double intStringToDouble(std::string &literal) {
	return static_cast<int>(doubleStringToDouble(literal));
}
static double floatStringToDouble(std::string &literal) {
	return static_cast<float>(doubleStringToDouble(literal));
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
	throw ScalarConverter::ConverterException();
}
static void	fractionalExceptionPrint(std::string const &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
	throw ScalarConverter::ConverterException();
}
static void printConversions(double const input) {
	if (isprint(static_cast<char>(input)))
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << getPrecision(input) << "f" << std::endl;
	std::cout << "double: " << input << getPrecision(input) << std::endl;
}
/* <----------------------------> */


void ScalarConverter::convert(std::string &literal) {
	double	(*stringToDouble[4])(std::string &literal) = {
		&charStringToDouble, &intStringToDouble,
		&floatStringToDouble, &doubleStringToDouble
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
		double convertedNumber = stringToDouble[literalType](literal);
		printConversions(convertedNumber);
	}
	catch (...) {}
}
