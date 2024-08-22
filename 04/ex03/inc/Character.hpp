/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:26:51 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 19:33:38 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define _MATERIAS_SIZE	4

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		/* >------ Cons/Destructors ------< */
		Character();
		Character(std::string const &_name);
		~Character();
		Character(Character const &other);
		Character			&operator=(Character const &other);

		/* >------ Others ------< */
		void				copyInventory(Character const &other);
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria	*_materias[_MATERIAS_SIZE];
		int			_materiasNumber;
};

#endif