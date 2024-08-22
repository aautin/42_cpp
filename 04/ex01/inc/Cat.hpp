/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by aautin            #+#    #+#             */
/*   Updated: 2024/08/21 18:29:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		/* >------ Cons/Destructors ------< */
		Cat();
		~Cat();
		Cat(Cat const &other);
		Cat	&operator=(Cat const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);

		/* >------ Announcers ------< */
		void	announce(std::string content) const;
		void	makeSound() const;

	private:
		Brain	*_brain;
};

#endif