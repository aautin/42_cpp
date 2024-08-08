/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:45:40 by aautin            #+#    #+#             */
/*   Updated: 2024/08/07 18:31:40 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.hpp"

/* Constructor-Destructor */
HumanB::HumanB(std::string const &name)
{
	this->name = name;
	this->weapon = NULL;
}
HumanB::~HumanB() {}


/* Others */
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void	HumanB::attack() const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon !?" << std::endl;
}