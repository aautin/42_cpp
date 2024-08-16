/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:26:28 by aautin            #+#    #+#             */
/*   Updated: 2024/08/16 20:50:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap character1;
	ScavTrap character2("Bob");

	character1.attack("Bob");
	character2.takeDamage(0);

	character1.takeDamage(2);
	character1.takeDamage(20);
	character1.beRepaired(1);
	character1.beRepaired(2);

	character1.guardGate();
	character1.guardGate();

	character2.guardGate();
}
