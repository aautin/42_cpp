/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:36:11 by aautin            #+#    #+#             */
/*   Updated: 2024/09/12 19:34:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bitset>
#include <climits>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

static double stod(std::string const &literal, int const type) {
		
}

static int	getType(std::string &literal) {
	if (*literal.begin() == '\'' && *literal.end() == '\'' && literal.length() == 3)
		return CHAR;

	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT;

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++) {
		if (!isdigit(*it) && *it != '.') {
			if (*it == 'f' && it + 1 == literal.end())
				return FLOAT;
			return NONE;
		}
	}

	if (literal.find('.', 0) == std::string::npos
		|| literal.find('.', 0) == literal.rfind('.', 0))
		return NONE;

	return DOUBLE;	
}

void ScalarConverter::convert(std::string const &literal) {
	
}
