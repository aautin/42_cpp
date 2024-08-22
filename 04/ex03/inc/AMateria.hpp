/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:24 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 19:20:17 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# include "ICharacter.hpp"

class AMateria
{
	public:
		/* >------ Cons/Destructors ------< */
		AMateria();
		virtual ~AMateria();
		AMateria(AMateria const &other);
		AMateria	&operator=(AMateria const &other);

		AMateria(std::string const &type);

		/* >------ Others ------< */
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string	_type;
};

#endif