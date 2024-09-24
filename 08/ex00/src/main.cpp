/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 14:27:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main() {

	/* Test the template (using container's iterator) on a vector of integers */
	std::vector<int> numbers;
	for (int i = 1; i <= 3; ++i)
		numbers.push_back(i);

	for (int i = 1; i <= 4; ++i) {
		try {
			int index = easyfind(numbers, i);
			std::cout << "[" << index << "]: " << i << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "[" << i << "]: not-found exception" << std::endl;
		}

	}

	return 0;
}
