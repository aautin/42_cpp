/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:03:16 by aautin            #+#    #+#             */
/*   Updated: 2024/08/29 14:32:27 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define NO_EXCEPTION	""
# define DEFAULT_NAME	"DefaultName"
# define DEFAULT_GRADE	75

# define MINIMAL_GRADE	150
# define MAXIMAL_GRADE	1

# include <exception>
# include <string>

class IException : public std::exception
{
	public:
		virtual const char* what() const throw() = 0;
};

class AForm;

class Bureaucrat
{
	public:
		/* >------ Cons/Destructors ------< */
		Bureaucrat(std::string const &name = DEFAULT_NAME, int grade = DEFAULT_GRADE);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);

		/* >------ Overloads ------< */
		Bureaucrat	&operator=(Bureaucrat const &other);

		/* >------ Setters ------< */
		void		upGrade();
		void		downGrade();

		/* >------ Getters ------< */
		std::string	getName() const;
		int			getGrade() const;

		/* >------ Actions ------< */
		void		signForm(AForm const &form,
							 std::string const &reason = NO_EXCEPTION) const;
		void		executeForm(AForm const &form,
							 std::string const &reason = NO_EXCEPTION) const;

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
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &it);

#endif