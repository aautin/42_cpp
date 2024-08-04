/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 02:02:48 by aautin           ###   ########.fr       */
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

	phoneBook.getCommand(0);
	printLine(NULL, EDGE);
	return EXIT_SUCCESS;
}
