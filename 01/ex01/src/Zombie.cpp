/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:38:37 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:06:58 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

/* Constructor-Destructor */
Zombie::Zombie(void)
{
	Zombie::setName("Default name");
	std::cout << "Zombie constructor called: " << Zombie::getName() << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called: " << Zombie::getName() << std::endl;
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
	std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
