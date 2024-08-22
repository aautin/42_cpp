/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 13:05:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
		void	makeSound() const;

	private:
		Brain	*_brain;
};

#endif