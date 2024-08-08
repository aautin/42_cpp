/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:55:29 by aautin            #+#    #+#             */
/*   Updated: 2024/08/08 21:37:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

static int	areArgsCorrect(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	std::string	filter = argv[1];
	if (filter.empty() || filter.length() > 1 || filter[0] < '1' || filter[0] > '4')
		return 0;

	return 1;
}
int			main(int argc, char **argv)
{
	if (!areArgsCorrect(argc, argv)) {
		std::cout << "Invalid arguments" << std::endl;
		std::cout << "Program needs a parameter ([1, 4])" << std::endl;
	}
	else {
		Harl	harl2_0(argv[1][0] - '0');

		harl2_0.complain("DEBUG");
		harl2_0.complain("INFO");
		harl2_0.complain("WARNING");
		harl2_0.complain("ERROR");

		harl2_0.complain("OTHER");
		harl2_0.complain("");

		harl2_0.complain("INFO");
		harl2_0.complain("INFO");
	}
}
