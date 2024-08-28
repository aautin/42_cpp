/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:44:08 by aautin            #+#    #+#             */
/*   Updated: 2024/08/28 17:21:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# define ASCII_TREES "               ,@@@@@@@,\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\
    ,&**&*&&*,@@@@@/@@@@@@,8888)88/8o\
   ,*&)*&&*&&*,@@@)@@@/@@@88)88888/88'\
   *&&*&*&/*&&*@@)@@/ /@@@88888)88888'\
   *&&*/ *&**&&@@) V /@@' `88)8 `/88'\
   `&*) ` /*&'    |.|        ) '|8'\
       |o|        | |         | |\
       |.|        | |         | |\
jgs ))/ ._)//_/__/  ,)_//__))/.  )_//__/_"

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