/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:54:37 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:02:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*heapZombie = new Zombie;
	heapZombie->Zombie::setName(name);

	return heapZombie;
}
