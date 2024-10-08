/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:30:53 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:10:03 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		/* Constructor-Destructor */
		HumanA(std::string const &name, Weapon &weapon);
		~HumanA();

		/* Others */
		void attack() const;
};

#endif