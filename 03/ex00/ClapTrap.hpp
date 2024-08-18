/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:26:28 by aautin            #+#    #+#             */
/*   Updated: 2024/08/18 15:02:38 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP\

# include <string>

class ClapTrap
{
	private:
		unsigned int	_damage;
		unsigned int	_energy;
		unsigned int	_hit;
		std::string		_name;

	public:
		/* OCCF */
		ClapTrap();
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap();

		/* Special constructor */
		ClapTrap(std::string const name);

		/* Actions */
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif