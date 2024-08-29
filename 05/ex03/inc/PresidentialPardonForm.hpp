/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 15:24:58 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_HPP
# define PRESIDENTIAL_PARDON_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);

		/* >------ Overloads ------< */
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);

		/* >------ Actions ------< */
		void				execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif