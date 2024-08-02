/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/02 17:27:00 by aautin           ###   ########.fr       */
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

	phoneBook.command(0);
	printLine(NULL, EDGE);
	return EXIT_SUCCESS;
}
