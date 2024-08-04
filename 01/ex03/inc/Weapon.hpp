/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:23:23 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 18:23:54 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string type;

	public:
		/* Constructor-Destructor */
		Weapon();
		Weapon(std::string const &type);
		~Weapon();

		/* Setter-Getter */
		std::string const	&getType() const;
		void				setType(std::string const &newType);
};

#endif