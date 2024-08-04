/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:28:03 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 03:03:34 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.h"
#include "Zombie.hpp"

int main(void)
{
	Zombie *david = newZombie("David");
	david->announce();

	Zombie *mathieu = newZombie("Mathieu");
	mathieu->announce();

	delete mathieu;
	delete david;

	randomChump("Baltazard");
	randomChump("Leonard");
}
