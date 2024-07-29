/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:04:05 by aautin            #+#    #+#             */
/*   Updated: 2024/07/29 19:30:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

class Megaphone {

	public:
		std::string stringToUpper(std::string& str);
};

std::string Megaphone::stringToUpper(std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] += 'A' - 'a';
		}
	}
	return str;
}

int main(int argc, char** argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		Megaphone string;
		for (int argvIndex = 1; argvIndex < argc; ++argvIndex) {
			std::string str = argv[argvIndex];
			std::cout << string.stringToUpper(str);
			if (argvIndex < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
