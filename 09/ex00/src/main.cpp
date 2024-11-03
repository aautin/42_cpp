/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by aautin            #+#    #+#             */
/*   Updated: 2024/11/03 19:31:46 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	try {
		if (argc == 2)
			BitcoinExchange(DATA_DEFAULT, argv[1]);
		else
			std::cout << "Wrong number of arguments" << std::endl;
	}
	catch (...) {
		std::cout << "Datafile of Inputfile isn't existing" << std::endl;
	}

	return 0;
}
