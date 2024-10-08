/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:15:05 by aautin            #+#    #+#             */
/*   Updated: 2024/08/27 18:25:54 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

/* >----------- Cons/Destructors -----------< */
Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: _name(name), _grade(grade) {
	std::cout << _name << ": Bureaucrat constructor called" << std::endl;

	if (grade > MINIMAL_GRADE)
		throw GradeTooLowException();
	if (grade < MAXIMAL_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {
	std::cout << _name << ": Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << _name << ": Bureaucrat copy constructor called" << std::endl;
}
/* <----------------------------> */


/* >----------- Setters -----------< */
void Bureaucrat::upGrade() {
	if (_grade == MAXIMAL_GRADE)
		throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::downGrade() {
	if (_grade == MINIMAL_GRADE)
		throw GradeTooLowException();

	_grade++;
}
/* <----------------------------> */


/* >----------- Getters -----------< */
std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
std::ostream &operator<<(std::ostream &out, Bureaucrat const &it) {
	out << it.getName() << ", bureaucrat grade " << it.getGrade() << ".";

	return out;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << _name << ": Bureaucrat copy assignment called" << std::endl;

	_grade = other._grade;
	return *this;
}
/* <----------------------------> */
