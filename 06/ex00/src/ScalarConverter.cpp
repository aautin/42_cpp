/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by aautin            #+#    #+#             */
/*   Updated: 2024/09/17 16:39:08 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> //atoi
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

static int getType(std::string &literal) {
	if (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'')
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
static double integerToFractional(int number) {
	double	divisor = 10.0;
	while (number / divisor >= 1.0)
		divisor *= 10;
	return static_cast<double>(number) / divisor;
}

/* >----------- String->Double conversion -----------< */
static double doubleStringToDouble(std::string &literal) {
	std::string::iterator it;
	for (it = literal.begin(); it != literal.end(); it++) {
		if (*it == '.') {
			it++;
			break;
		}
	}
	int	integerPart = atoi(literal.c_str());
	int	fractionalPart;
	if (it == literal.end())
		fractionalPart = 0;
	else
		fractionalPart = atoi(literal.substr(it - literal.begin()).c_str());
	return static_cast<double>(integerPart) + integerToFractional(fractionalPart);
}
static double charStringToDouble(std::string &literal) {
	return literal.at(1);
}
static double intStringToDouble(std::string &literal) {
	return static_cast<int>(doubleStringToDouble(literal));
}
static double floatStringToDouble(std::string &literal) {
	return static_cast<float>(doubleStringToDouble(literal));
}
/* <----------------------------> */


/* >----------- Print -----------< */
static void notypeExceptionPrint() {
	std::cout << "Literal incorrect." << std::endl;	
	throw ScalarConverter::ConverterException();
}
static void	floatExceptionPrint(std::string const &literal) {
	std::string doubleFormat = literal.substr(0, literal.length() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << doubleFormat << std::endl;
	throw ScalarConverter::ConverterException();
}
static void	doubleExceptionPrint(std::string const &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
	throw ScalarConverter::ConverterException();
}
/* <----------------------------> */


static void	printType(int const type) {
	switch (type) {
		case CHAR:
			std::cout << "CHAR" << std::endl;
			break;
		case INT:
			std::cout << "INT" << std::endl;
			break;
		case FLOAT:
			std::cout << "FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "DOUBLE" << std::endl;
			break;
		case FLOAT_EXCEPTION:
			std::cout << "FLOAT_EXCEPTION" << std::endl;
			break;
		case DOUBLE_EXCEPTION:
			std::cout << "DOUBLE_EXCEPTION" << std::endl;
			break;
		case NONE:
			std::cout << "NONE" << std::endl;
			break;
	}
}
void ScalarConverter::convert(std::string &literal) {
	double	(*stringToDouble[4])(std::string &literal) = {
		&charStringToDouble, &intStringToDouble,
		&floatStringToDouble, &doubleStringToDouble
	};

	int const literalType = getType(literal);
	printType(literalType);

	try {
		switch (literalType) {
			case NONE:
				notypeExceptionPrint();
			case FLOAT_EXCEPTION:
				floatExceptionPrint(literal);
			case DOUBLE_EXCEPTION:
				doubleExceptionPrint(literal);
		}
		double convertedNumber = stringToDouble[literalType](literal);
		std::cout << convertedNumber << std::endl;
	}
	catch (...) {}
}
