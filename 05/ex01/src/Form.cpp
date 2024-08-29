/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:59:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 13:38:36 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Form.hpp"

/* >----------- Cons/Destructors -----------< */
Form::Form(std::string const &name, int const toSign, int const toExecute)
	: _name(name), _gradeToSign(toSign), _gradeToExecute(toExecute) {
	std::cout << _name << ": Form constructor called" << std::endl;

	_isSigned = false;

	if (toSign < MAXIMAL_GRADE || toExecute < MAXIMAL_GRADE)
		throw GradeTooHighException();

	if (toSign > MINIMAL_GRADE || toExecute > MINIMAL_GRADE)
		throw GradeTooLowException();
}

Form::~Form() {
	std::cout << _name << ": Form destructor called" << std::endl;
}

Form::Form(Form const &other) : _name(other._name),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << _name << ": Form copy constructor called" << std::endl;

	_isSigned = other._isSigned;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
Form &Form::operator=(Form const &other) {
	std::cout << _name << ": Form copy assignment called" << std::endl;

	_isSigned = other._isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &outputStream, Form const &it) {
	std::string	isSigned = (it.getIsSigned() == true) ? "signed" : "not-signed";

	outputStream << it.getName() << ": " << isSigned
		<< ", gradeToSign " << it.getGradeToSign()
		<< ", gradeToExecute " << it.getGradeToExecute() << ".";

	return outputStream;
}
/* <----------------------------> */


/* >----------- Actions -----------< */
void Form::beSigned(Bureaucrat const &signatory) {
	if (_isSigned)
		throw FormAlreadySigned();

	if (signatory.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_isSigned = true;
}
/* <----------------------------> */
