/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/27 18:35:30 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Form
{
	public:
		/* >------ Cons/Destructors ------< */
		Form(std::string const &name = DEFAULT_NAME,
			int const toSign = DEFAULT_GRADE, int const toExecute = DEFAULT_GRADE);
		~Form();
		Form(Form const &other);

		/* >------ Others ------< */
		void	beSigned(Bureaucrat const &signatory);
		void	signForm(Bureaucrat const &signatory, IException &e) const;

		/* >------ Exceptions ------< */
		class GradeTooHighException : public IException
		{
			public:
				GradeTooHighException() {}
				virtual const char*	what() const throw() { return "Too high"; }
		};
		class GradeTooLowException : public IException
		{
			public:
				GradeTooLowException() {}
				virtual const char*	what() const throw() { return "Too low"; }
		};

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

#endif