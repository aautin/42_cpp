/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:21:21 by aautin            #+#    #+#             */
/*   Updated: 2024/10/10 19:24:09 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "PmergeMe.hpp"

/* >----------- Utils -----------< */
void		PmergeMe::printTimeSpent(double time, std::string containerName) {
	std::cout << "Time to process a range of " << _size << "elements with "
		<< containerName << " :  " << time << " us" << std::endl;
}
/* <----------------------------> */


/* >----------- Operations on containers -----------< */
void		PmergeMe::addNumber(int number) {
	if (number < 0)
		throw std::exception();

	_list.push_back(number);
	_vector.push_back(number);
	_size++;
}
/* <----------------------------> */


/* >----------- Sorting -----------< */
void		PmergeMe::sortList() {
	
}

void		PmergeMe::sortVector() {
	
}

void		PmergeMe::sortContainers() {
	std::clock_t start, end;

	start = std::clock();
	sortList();
	end = std::clock();
	printTimeSpent(static_cast<double>(end - start), "std::list");

	start = std::clock();
	sortVector();
	end = std::clock();
	printTimeSpent(static_cast<double>(end - start), "std::vector");
}
/* <----------------------------> */
