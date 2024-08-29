/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 14:20:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_HPP
# define ROBOTOMY_REQUEST_HPP

# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);

		/* >------ Overloads ------< */
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);

		/* >------ Actions ------< */
		void				execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif