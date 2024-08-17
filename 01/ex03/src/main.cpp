/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:21:45 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:15:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.HumanA::attack();
		club.Weapon::setType("some other type of club");
		bob.HumanA::attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.HumanB::attack();
		jim.HumanB::setWeapon(club);
		jim.HumanB::attack();
		club.Weapon::setType("some other type of club");
		jim.HumanB::attack();
	}

	return 0;
}