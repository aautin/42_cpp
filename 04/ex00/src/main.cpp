/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:09:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/21 18:16:42 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* i = new Animal();
	const Animal* j = new Cat();
	const Animal* k = new Dog();
	const WrongAnimal* w = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	k->makeSound();
	w->makeSound();

	delete i;
	delete j;
	delete k;
	delete w;
}
