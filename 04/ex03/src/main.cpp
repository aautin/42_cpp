/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:26:17 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 19:41:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {

	std::cout << std::endl << "Construct a Character and AMaterials" << std::endl;
	ICharacter *player1 = new Character("Bob");
	ICharacter *player2 = new Character("Timothee");
	AMateria *cure1 = new Cure;
	AMateria *cure2 = new Cure;
	AMateria *ice1 = new Ice;
	AMateria *ice2 = new Ice;

	AMateria *ice3 = new Ice;




	std::cout << std::endl << "Equip AMaterials" << std::endl;
	player1->equip(cure1);
	player1->equip(ice1);



	std::cout << std::endl << "Use available/unavailable AMaterials" << std::endl;
	player1->use(0, *player2);
	player1->use(1, *player2);
	player1->use(2, *player2);
	
	player2->use(0, *player1);



	std::cout << std::endl << "Re-equip too many AMaterials" << std::endl;
	player1->equip(cure2);
	player1->equip(ice2);
	player1->equip(ice3);



	std::cout << std::endl << "Destruct a Character and AMaterials" << std::endl;
	delete player1;
	delete player2;
	delete ice3;
}
