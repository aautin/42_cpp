/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by aautin            #+#    #+#             */
/*   Updated: 2024/10/01 19:26:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main() {

	try {
		BitcoinExchange("data.csv", "input");
	}
	catch (...) {
		std::cout << "Exception caught" << std::endl;
	}

	return 0;
}
