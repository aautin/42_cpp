/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:18:53 by aautin            #+#    #+#             */
/*   Updated: 2024/10/21 17:52:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	PmergeMe it;
	try {
		for (int i = 1; i < argc; ++i) {
			std::stringstream stream(argv[i]);
			std::string word;
			while (stream >> word) {
				char *endPtr;
				long number = std::strtol(word.c_str(), &endPtr, 10);
				if (*endPtr != '\0')
					throw std::exception();
				if (errno == ERANGE)
					throw std::exception();
				if (number <= 0 || std::numeric_limits<int>::max() < number)
					throw std::exception();
				it.addNumber(number);
			}
		}
		it.sortContainers();
	}
	catch (std::exception const & e) {
		std::cout << "The input is incorrect" << std::endl;
	}
}
