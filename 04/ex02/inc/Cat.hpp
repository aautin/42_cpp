/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:51 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 13:05:29 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
		void	makeSound() const;

	private:
		Brain	*_brain;
};

#endif