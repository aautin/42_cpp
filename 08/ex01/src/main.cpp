/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 16:28:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {

	std::cout << "\n----------------" << std::endl;
	/* Create Span */
	Span mySpan(15000);


	std::cout << "\n----------------" << std::endl;
	/* Try to find the shortestSpan and the longestSpan */
	try {
		int shortest = mySpan.shortestSpan();
		std::cout << "Shortest: " << shortest << std::endl;
		int longest = mySpan.longestSpan();
		std::cout << "Longest: " << longest << std::endl;
	}
	catch (...) {
		std::cout << "Couldn't find the short/longest" << std::endl;
	}


	std::cout << "\n----------------" << std::endl;
	/* Try to add numbers from -20000 to 20000 included */
	int i = 0;
	try {
		for (i = -20000; i <= 20000; ++i) {
			if (i % 2 == 0)
				mySpan.add(i);
		}
	}
	catch (std::exception) {
		std::cout << "Couldn't add the value " << i << std::endl;
	}


	std::cout << "\n----------------" << std::endl;
	/* Try to find the shortestSpan and the longestSpan */
	try {
		int shortest = mySpan.shortestSpan();
		std::cout << "Shortest: " << shortest << std::endl;
		int longest = mySpan.longestSpan();
		std::cout << "Longest: " << longest << std::endl;
	}
	catch (...) {
		std::cout << "Couldn't find the short/longest" << std::endl;
	}


	std::cout << "\n----------------" << std::endl;
	return 0;
}
