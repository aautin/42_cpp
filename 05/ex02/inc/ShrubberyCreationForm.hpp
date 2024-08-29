/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 13:33:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# define ASCII_TREES "\n               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&**&*&&*,@@@@@/@@@@@@,8888)88/8o\n\
   ,*&)*&&*&&*,@@@)@@@/@@@88)88888/88'\n\
   *&&*&*&/*&&*@@)@@/ /@@@88888)88888'\n\
   *&&*/ *&**&&@@) V /@@' `88)8 `/88'\n\
   `&*) ` /*&'    |.|        ) '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    ))/ ._)//_/__/  ,)_//__))/.  )_//__/_\n"

# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);

		/* >------ Overloads ------< */
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);

		/* >------ Others ------< */
		void					execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif