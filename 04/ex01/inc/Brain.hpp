/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:17:47 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 11:33:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define IDEAS_NUMBER_MAX	100

# include <string>

class Brain
{
	public:
		/* >------ Cons/Destructors ------< */
		Brain();
		~Brain();
		Brain(Brain const &other);
		Brain	&operator=(Brain const &other);

		/* >------ Get/Set ------< */
		std::string	getIdea(int ideaIndex) const;
		void		setIdea(std::string const &newIdea);

	private:
		int			_ideasNumber;
		std::string	_ideas[IDEAS_NUMBER_MAX];
};

#endif