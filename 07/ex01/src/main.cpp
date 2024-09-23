/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:49:59 by aautin            #+#    #+#             */
/*   Updated: 2024/09/23 17:17:47 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TABLE_SIZE	3

#include <iostream>
#include <string>

#include "Iter.hpp"

void toUpperCase(std::string &content) {
	for (std::string::iterator it = content.begin(); it != content.end(); it++) {
		*it = toupper(*it);
	}
}

void increase(int &number) {
	number++;
}

int main( void ) {

	/* >------TEST ON A STD::STRING ARRAY------< */
	std::string *stringTable = new std::string[TABLE_SIZE];
	stringTable[0] = "Bonjour";
	stringTable[1] = "12345 a";
	stringTable[2] = "test numero 3!";

	iter<std::string>(stringTable, TABLE_SIZE, &toUpperCase);

	for (int i = 0; i != TABLE_SIZE; i++)
		std::cout << "[" << i << "]: " << stringTable[i] << std::endl;
	std::cout << std::endl;


	/* >------TEST ON A INT ARRAY------< */
	int *intTable = new int[TABLE_SIZE];
	intTable[0] = 1;
	intTable[1] = -1;
	intTable[2] = 10;

	iter<int>(intTable, TABLE_SIZE, &increase);

	for (int i = 0; i != TABLE_SIZE; i++)
		std::cout << "[" << i << "]: " << intTable[i] << std::endl;

	return 0;
}
