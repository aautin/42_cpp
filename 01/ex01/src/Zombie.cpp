/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:38:37 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 02:51:01 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

/* Constructor-Destructor */
Zombie::Zombie(void)
{
	setName("Default name");
	std::cout << "Zombie constructor called: " << getName() << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called: " << getName() << std::endl;
}


/* Others */
void	Zombie::setName(std::string const &name)
{
	this->name = name;
}
std::string	Zombie::getName( void )
{
	return name;
}
void	Zombie::announce( void )
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
