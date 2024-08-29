/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:17:49 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 17:19:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Intern.hpp"

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
	std::string const	formNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	AForm* (*forms[3])(std::string const &) = { &createShrubberyForm, &createRobotomyForm, &createPresidentialForm };

	for (int i = 0; i < 3; i++) {
		if (formName.compare(formNames[i]) == 0)
			return forms[i](target);
	}

	throw FormUnknownException();
}
