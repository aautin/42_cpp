/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 13:15:50 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class AForm
{
	public:
		/* >------ Cons/Destructors ------< */
		AForm(std::string const &name = DEFAULT_NAME,
			int const toSign = DEFAULT_GRADE, int const toExecute = DEFAULT_GRADE);
		~AForm();
		AForm(AForm const &other);

		/* >------ Get/Setters ------< */
		std::string		getName() const { return _name; }
		int				getIsSigned() const { return _isSigned; }
		int				getGradeToSign() const { return _gradeToSign; }
		int				getGradeToExecute() const { return _gradeToExecute; }
		void			setIsSigned(int isSigned) { _isSigned = isSigned; }

		/* >------ Others ------< */
		void			beSigned(Bureaucrat const &signatory);

		/* >------ Overloads ------< */
		AForm			&operator=(AForm const &other);

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
		class FormNotSigned : public IException
		{
			public:
				FormNotSigned() {}
				virtual const char*	what() const throw() { return "Form not signed"; }
		};
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &outputStream, AForm const &it);

#endif