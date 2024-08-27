/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:58 by aautin            #+#    #+#             */
/*   Updated: 2024/08/27 18:10:43 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {

	std::cout << std::endl << "-----------CONSTRUCTION-----------" << std::endl;
	try {
		Bureaucrat Default(DEFAULT_NAME, DEFAULT_GRADE);
	}
	catch (IBureaucratException &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *Bob;
	try {
		Bob = new Bureaucrat("Bob", MAXIMAL_GRADE - 1);
	}
	catch (IBureaucratException &e) {
		std::cout << e.what() << std::endl;
		Bob = NULL;
	}

	Bureaucrat *Tom;
	try {
		Tom = new Bureaucrat("Tom", MINIMAL_GRADE + 1);
	}
	catch (IBureaucratException &e) {
		std::cout << e.what() << std::endl;
		Tom = NULL;
	}

	Bureaucrat *Arthur;
	try {
		Arthur = new Bureaucrat("Arthur", 3);
	}
	catch (IBureaucratException &e) {
		std::cout << e.what() << std::endl;
		Arthur = NULL;
	}

	std::cout << std::endl << "-----------OTHER TESTS-----------" << std::endl;
	if (Arthur != NULL) {
		std::cout << *Arthur << std::endl;
		while (1) {
			try {
				Arthur->upGrade();
			}
			catch (IBureaucratException &e) {
				std::cout << e.what() << std::endl;
				break ;
			}
			std::cout << *Arthur << std::endl;
		}
	}


	std::cout << std::endl << "-----------DESTRUCTION-----------" << std::endl;
	delete Tom;
	delete Bob;
	delete Arthur;
}
