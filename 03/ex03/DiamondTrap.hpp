/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:26:28 by aautin            #+#    #+#             */
/*   Updated: 2024/08/19 17:19:52 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	DIAMONDTRAP_HPP
# define	DIAMONDTRAP_HPP

# include <string>

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		/* OCCF */
		DiamondTrap();
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap &operator=(DiamondTrap const &other);
		~DiamondTrap();

		DiamondTrap(std::string name);

		void whoAmI() const;
	private:
		std::string	name;
};

#endif