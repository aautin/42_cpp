/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:50 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 17:23:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		/* >------ Cons/Destructors ------< */
		Cure();
		~Cure();
		Cure(Cure const &other);
		Cure	&operator=(Cure const &other);

		/* >------ Others ------< */
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif