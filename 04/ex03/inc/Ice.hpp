/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:50 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 17:23:29 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		/* >------ Cons/Destructors ------< */
		Ice();
		~Ice();
		Ice(Ice const &other);
		Ice	&operator=(Ice const &other);

		/* >------ Others ------< */
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif