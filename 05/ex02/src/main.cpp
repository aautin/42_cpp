/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:58 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 13:20:42 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	std::cout << std::endl << "-----------CREATE AND UPGRADE BUREAUCRAT-----------" << std::endl;
	Bureaucrat *Arthur;
	try {
		Arthur = new Bureaucrat("Arthur", 14);
	}
	catch (IException &e) {
		std::cout << e.what() << std::endl;
		Arthur = NULL;
	}

	if (Arthur != NULL) {
		std::cout << *Arthur << std::endl;
		while (Arthur->getGrade() > 10) {
			try {
				Arthur->upGrade();
			}
			catch (IException &e) {
				std::cout << e.what() << std::endl;
				break ;
			}
			std::cout << *Arthur << std::endl;
		}
	}

	std::cout << std::endl << "-----------CREATE SHRUBBERYCREATIONFORM AND SIGN IT-----------" << std::endl;
	ShrubberyCreationForm myForm("myForm");
	std::cout << myForm << std::endl;
	std::cout << *Arthur << std::endl;
	try {
		myForm.beSigned(*Arthur);
		Arthur->signForm(myForm, "");
	}
	catch (IException &e) {
		Arthur->signForm(myForm, e.what());
	}
	std::cout << myForm << std::endl;

	std::cout << std::endl << "-----------DESTRUCTION-----------" << std::endl;
	delete Arthur;
}
