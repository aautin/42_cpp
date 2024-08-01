/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/02 00:24:03 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void printField(std::string field)
{
	if (field.length() > 10) {
		field.resize(10);
		field[9] = '.';
	}
	else {
		for (int i = 0; i + field.length() < 10; i++)
			std::cout << ' ';
	}
	std::cout << field;
}

void printLine(char const *line)
{
	std::cout << line << std::endl;
}

void printInvalid(int trialNumber, char const *invalidType)
{
	std::cout << "Invalid " << invalidType << " (" << trialNumber << "/3).";
	if (trialNumber < 3)
		std::cout << " Try again.";
	std::cout << std::endl;
}

std::string readLine(char const *prompt)
{
	const std::string PROMPT_COLOR = "\033[31m";
	const std::string DEFAULT_COLOR = "\033[0m";
	std::cout << PROMPT_COLOR << prompt << DEFAULT_COLOR << " ➡️  ";

	std::string line;
	std::cin >> line;
	if (std::cin.eof())
		std::cout << std::endl;
	return line;
}
