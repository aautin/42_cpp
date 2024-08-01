/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/01 23:38:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <cstdlib>
#include <iostream>

#include "PhoneBook.hpp"
#include "userInterface.hpp"

int main(void)
{
	PhoneBook	phoneBook;

	printLine(EDGE);
	while (true) {
		std::string command = readLine("Phonebook");
		if (command.compare("SEARCH") == 0)
			phoneBook.search(0);
		else if (command.compare("ADD") == 0)
			phoneBook.add(0);
		else if (command.compare("EXIT") == 0)
			break ;
		else {
			int failsNumber = phoneBook.getConsecutiveFailsNumber();
			if (failsNumber == 2) {
				printInvalid(3, "command");
				break ;
			}
			printInvalid(failsNumber + 1, "command");
			phoneBook.setConsecutiveFailsNumber(failsNumber + 1);
		}
	}
	printLine(EDGE);
	return EXIT_SUCCESS;
}
