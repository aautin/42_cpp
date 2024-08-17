/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:45:40 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:13:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.hpp"

/* Constructor-Destructor */
HumanB::HumanB(std::string const &name)
{
	this->name = name;
	weapon = NULL;
}
HumanB::~HumanB() {}

/* Others */
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->Weapon::getType() << std::endl;
	else
		std::cout << name << " has no weapon !?" << std::endl;
}
