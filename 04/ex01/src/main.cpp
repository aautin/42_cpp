/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:09:13 by aautin            #+#    #+#             */
/*   Updated: 2024/08/22 11:34:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// const Animal* i = new Cat();
	// const Animal* j = new Dog();
	Brain* k = new Brain();

	k->setIdea("I love cats");
	k->setIdea("But I prefer dogs");

	std::cout << k->getIdea(0) << std::endl;
	std::cout << k->getIdea(1) << std::endl;
	std::cout << k->getIdea(2) << std::endl;

	// delete i;
	// delete j;
	delete k;

	return 0;
}
