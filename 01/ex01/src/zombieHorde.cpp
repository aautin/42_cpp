/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:38:10 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 03:43:08 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.h"
#include "Zombie.hpp"


Zombie*	newZombie( std::string name )
{
	Zombie *zombie = new Zombie;
	zombie->setName(name);
	return zombie;
}
Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde[N];

	for (int i = 0; i < N; i++) {
		horde[i] = newZombie(name);
	}
}
