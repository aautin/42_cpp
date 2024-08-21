/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by aautin            #+#    #+#             */
/*   Updated: 2024/08/21 16:45:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

# include <string>

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		/* >------ Cons/Destructors ------< */
		Dog();
		~Dog();
		Dog(Dog const &other);
		Dog	&operator=(Dog const &other);

		/* >------ Get/Set ------< */
		std::string	getType() const;
		void		setType(std::string newType);

		/* >------ Announcers ------< */
		void	announce(std::string content) const;
		void	makeSound() const;
};

#endif