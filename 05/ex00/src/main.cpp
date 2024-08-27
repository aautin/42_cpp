/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:58 by aautin            #+#    #+#             */
/*   Updated: 2024/08/27 16:57:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
	
	try {
		Bureaucrat Default(DEFAULT_NAME, DEFAULT_GRADE);
	}
	catch (IGradeException &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat *Bob;
	try {
		Bob = new Bureaucrat("Bob", MAXIMAL_GRADE - 1);
	}
	catch (IGradeException &e) {
		std::cout << e.what() << std::endl;
		Bob = NULL;
	}

	Bureaucrat *Tom;
	try {
		Tom = new Bureaucrat("Tom", MINIMAL_GRADE + 1);
	}
	catch (IGradeException &e) {
		std::cout << e.what() << std::endl;
		Tom = NULL;
	}

	Bureaucrat *Arthur;
	try {
		Arthur = new Bureaucrat("Arthur", DEFAULT_GRADE);
	}
	catch (IGradeException &e) {
		std::cout << e.what() << std::endl;
		Arthur = NULL;
	}

	delete Tom;
	delete Bob;
	delete Arthur;
}
