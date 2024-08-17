/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:45:40 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:09:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.hpp"

/* Constructor-Destructor */
HumanA::HumanA(std::string const &name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}
HumanA::~HumanA() {}

/* Others */
void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.Weapon::getType() << std::endl;
}
