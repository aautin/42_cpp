/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by aautin            #+#    #+#             */
/*   Updated: 2024/08/30 11:55:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

static char toChar(std::string const &literal) {
	char buffer = 0;
	(void) literal;

	return buffer;
}

static int toInt(std::string const &literal) {
	int buffer = 0;
	(void) literal;

	return buffer;
}

static float toFloat(std::string const &literal) {
	float buffer = 0;
	(void) literal;

	return buffer;
}

static double toDouble(std::string const &literal) {
	double buffer = 0;
	(void) literal;

	return buffer;
}

void ScalarConverter::convert(std::string const &literal) {
	char charType = toChar(literal);
	if (0 <= charType && charType <= 31)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << charType << std::endl;
	std::cout << "int: " << toInt(literal) << std::endl;
	std::cout << "float: " << toFloat(literal) << std::endl;
	std::cout << "double: " << toDouble(literal) << std::endl;
}
