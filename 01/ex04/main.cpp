/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:31:19 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "File.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Wrong arguments" << std::endl;
		std::cout << "Must be: [filename] [string_target] [string_replacement]" << std::endl;
	}
	else {
		std::string	source = argv[1];

		File sourceFile(source);
		sourceFile.File::load(sourceFile.getName());
		sourceFile.File::replace((std::string) argv[2], (std::string) argv[3]);
		sourceFile.File::stream(source + ".replace");
	}
}
