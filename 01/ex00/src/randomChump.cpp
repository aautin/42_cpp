/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:54:37 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:01:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	stackZombie;
	stackZombie.Zombie::setName(name);
	stackZombie.Zombie::announce();
}
