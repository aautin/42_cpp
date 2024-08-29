/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:20:06 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 13:29:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ShrubberyCreationForm.hpp"

/* >----------- Cons/Destructors -----------< */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {
	std::cout << _target << ": ShrubberyCreation default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << _target << ": ShrubberyCreation destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << _target << ": ShrubberyCreation copy constructor called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	std::cout << _target << ": ShrubberyCreation copy assigment called" << std::endl;

	setIsSigned(other.getIsSigned());
	_target = other._target;
	return *this;
}
/* <----------------------------> */


/* >----------- Others -----------< */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw FormNotSigned();

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << ASCII_TREES << std::endl;
}
/* <----------------------------> */
