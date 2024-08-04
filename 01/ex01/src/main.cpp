/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:28:03 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 03:46:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.h"
#include "Zombie.hpp"

#define ZOMBIES_NUMBER 10

int main(void)
{
	Zombie **horde = zombieHorde(ZOMBIES_NUMBER, "Zombidoubidou");

	for (int i = 0; i < ZOMBIES_NUMBER; i++) {
		horde[i].announce();
	}

	for (int i = 0; i < ZOMBIES_NUMBER; i++) {
		delete horde[i];
	}
}
