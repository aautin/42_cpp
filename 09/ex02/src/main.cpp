/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:18:53 by aautin            #+#    #+#             */
/*   Updated: 2024/10/21 15:55:28 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	PmergeMe it;
	it.addNumber(3);
	it.addNumber(30);
	it.addNumber(1);
	it.addNumber(7);
	it.addNumber(8);
	it.addNumber(5);
	it.addNumber(5);
	it.addNumber(5);
	it.addNumber(10);
	it.addNumber(6);
	it.addNumber(5);
	it.addNumber(4);
	it.addNumber(2);
	it.sortContainers();
}
