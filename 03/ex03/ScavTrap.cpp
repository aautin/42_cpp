/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:37:24 by aautin            #+#    #+#             */
/*   Updated: 2024/08/16 20:49:49 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

/* OCCF */
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;

	damage = 20;
	energy = 50;
	hit = 100;
}
ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = other;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap copy assignment constructor called." << std::endl;

	damage = other.damage;
	energy = other.energy;
	hit = other.hit;
	name = other.name;

	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called." << std::endl;
}

/* Special constructor */
ScavTrap::ScavTrap(std::string const name)
{
	damage = 20;
	energy = 50;
	hit = 100;
	this->name = name;
	std::cout << "ScavTrap name constructor called." << std::endl;
}

/* Actions */
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}