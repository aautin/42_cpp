/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/28 14:43:07 by aautin           ###   ########.fr       */
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

		/* >------ Getters ------< */
		std::string	getName() const { return _name; }
		int			getIsSigned() const { return _isSigned; }
		int			getGradeToSign() const { return _gradeToSign; }
		int			getGradeToExecute() const { return _gradeToExecute; }

		/* >------ Others ------< */
		void		beSigned(Bureaucrat const &signatory);
		void		signForm(Bureaucrat const &signatory, std::string const &reason) const;

		/* >------ Overloads ------< */
		Form		&operator=(Form const &other);

		/* >------ Exceptions ------< */
		class GradeTooHighException : public IException
		{
			public:
				GradeTooHighException() {}
				virtual const char*	what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public IException
		{
			public:
				GradeTooLowException() {}
				virtual const char*	what() const throw() { return "Grade too low"; }
		};
		class FormAlreadySigned : public IException
		{
			public:
				FormAlreadySigned() {}
				virtual const char*	what() const throw() { return "Form already signed"; }
		};

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &outputStream, Form const &it);

#endif