/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:27:20 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 18:23:47 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Weapon.hpp"

/* Constructor-Destructor */
Weapon::Weapon()
{
	this->type = "default weapon type";
}
Weapon::Weapon(std::string const &type)
{	
	this->type = type;
}
Weapon::~Weapon() {}


/* Setter-Getter */
std::string const	&Weapon::getType() const
{
	return this->type;
}
void	Weapon::setType(std::string const &newType)
{
	this->type = newType;
}
