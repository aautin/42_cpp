/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:58 by aautin            #+#    #+#             */
/*   Updated: 2024/08/28 14:45:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	std::cout << std::endl << "-----------CREATE AND UPGRADE BUREAUCRAT-----------" << std::endl;
	Bureaucrat *Arthur;
	try {
		Arthur = new Bureaucrat("Arthur", 3);
	}
	catch (IException &e) {
		std::cout << e.what() << std::endl;
		Arthur = NULL;
	}

	if (Arthur != NULL) {
		std::cout << *Arthur << std::endl;
		while (1) {
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

	std::cout << std::endl << "-----------CREATE AND SIGN A FORM-----------" << std::endl;
	Form myForm("taxes", 72, 61);
	std::cout << *Arthur << std::endl;
	std::cout << myForm << std::endl;
	try {
		myForm.beSigned(*Arthur);
		myForm.signForm(*Arthur, "");
	}
	catch (IException const &e) {
		myForm.signForm(*Arthur, e.what());
	}

	std::cout << std::endl << "-----------FAIL TO SIGN A SIGNED FORM-----------" << std::endl;
	try {
		myForm.beSigned(*Arthur);
		myForm.signForm(*Arthur, "");
	}
	catch (IException const &e) {
		myForm.signForm(*Arthur, e.what());
	}

	std::cout << std::endl << "-----------DOWNGRADE ARTHUR AND FAIL TO SIGN A FORM-----------" << std::endl;
	Arthur->downGrade();
	Form myForm2("taxes", 1, 61);
	std::cout << *Arthur << std::endl;
	std::cout << myForm2 << std::endl;
	try {
		myForm2.beSigned(*Arthur);
		myForm2.signForm(*Arthur, "");
	}
	catch (IException const &e) {
		myForm2.signForm(*Arthur, e.what());
	}


	std::cout << std::endl << "-----------DESTRUCTION-----------" << std::endl;
	delete Arthur;
}
