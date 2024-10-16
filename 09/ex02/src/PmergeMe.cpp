/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:21:21 by aautin            #+#    #+#             */
/*   Updated: 2024/10/17 20:31:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NO_VALUE	-1
#define FIRST		0
#define SECOND		1
#define DONE		1

#include <ctime>
#include <iostream>

#include "PmergeMe.hpp"

/* >----------- Utils -----------< */
void PmergeMe::printTimeSpent(double time, std::string containerName) {
	std::cout << "Time to process a range of " << _size << "elements with "
		<< containerName << " :  " << time << " us" << std::endl;
}

static int getJacobsthalElement(int index) {
	switch (index) {
		case -2:
			return 0;
		case -1:
			return 1;
		default:
			return getJacobsthalElement(index - 1) + (2 * getJacobsthalElement(index - 2));
	}
}
/* <----------------------------> */


/* >----------- Operations on containers -----------< */
void PmergeMe::addNumber(int number) {
	if (number < 0)
		throw std::exception();

	_list.push_back(number);
	_vector.push_back(number);
	_size++;
}
/* <----------------------------> */


/* >----------- Sorting -----------< */
/* >----------- List -----------< */
void PmergeMe::sortList() {
	
}
/* <----------------------------> */

/* >----------- Vector -----------< */
static void sortVectorPairs(std::vector<std::pair<int, int> > pairs) {
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it < pairs.end(); ++it) {
		if (it->first > it->second) {
			int second = it->first;
			it->first = it->second;
			it->second = second;
		}
	}
}

static std::vector<int> halfVector(std::vector<int> it, int mode) {
	int	start;
	int	end;

	if (mode == FIRST) {
		start = 0;
		end = it.size() / 2;
	}
	else {
		start = it.size() / 2;
		end = it.size();
	}

	std::vector<int> half;
	while (start < end) {
		half.push_back(it[start]);
		start++;
	}
	return half;
}

static std::vector<int> mergeInsertionSortVector(
	std::vector<int> left, std::vector<int> right) {
	if (left.size() > 1)
		left = mergeInsertionSortVector(halfVector(left, FIRST), halfVector(left, SECOND));
	if (right.size() > 1)
		right = mergeInsertionSortVector(halfVector(right, FIRST), halfVector(right, SECOND));

	std::vector<int>::iterator rightIt;
	for (rightIt = right.begin(); rightIt < right.end(); ++rightIt) {
		std::vector<int>::iterator leftIt;
		for (leftIt = left.begin(); leftIt < left.end(); ++leftIt) {
			if (*rightIt <= *leftIt) {
				left.insert(leftIt, *rightIt);
				break;
			}
		}
		if (leftIt == left.end())
			left.push_back(*rightIt);
	}

	return left;
}

static void insert(std::vector<int> destination, int newElement) {
	std::vector<int>::iterator it;
	for (it = destination.begin(); it < destination.end(); ++it) {
		if (newElement <= *it) {
			destination.insert(it, newElement);
			return ;
		}
	}
	destination.push_back(newElement);
}

static void insertLastNumbers(std::vector<int> s, std::vector<std::pair<int, int> > p) {
	int index = 0;
	do {
		index = getJacobsthalElement(index);

		for (int i = index; i >= 0; --i) {
			if (p.at(i).second != DONE) {
				insert(s, p.at(i).first);
				p.at(i).second = DONE;
			}
		}

		index++;
	} while (static_cast<std::vector<int>::size_type>(index) < p.size());
}

void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > pairs;

	{
		std::vector<int>::iterator it;
		for (it = _vector.begin(); it < _vector.end(); ++it) {
			std::vector<int>::iterator previous = it;
			if (++it == _vector.end()) {
				pairs.push_back(std::make_pair<int, int>(*previous, NO_VALUE));
				break;
			}
			pairs.push_back(std::make_pair<int, int>(*previous, *it));
		}
	}

	sortVectorPairs(pairs);

	std::vector<int> s;
	std::vector<std::pair<int, int> > p;

	{
		std::vector<std::pair<int, int> >::iterator it;
		for (it = pairs.begin(); it < pairs.end(); ++it) {
			s.push_back(it->second);
			if (it->first != NO_VALUE)
				p.push_back(std::make_pair<int, int>(it->first, !DONE));
		}
	}

	s = mergeInsertionSortVector(halfVector(s, FIRST), halfVector(s, SECOND));
	int smallestElementOfS = s[0];
	{
		std::vector<std::pair<int, int> >::iterator pairsIterator;
		for (pairsIterator = pairs.begin(); pairsIterator < pairs.end(); ++pairsIterator) {
			if (pairsIterator->second == smallestElementOfS) {
				s.insert(s.begin(), pairsIterator->first);

				std::vector<std::pair<int, int> >::iterator pIterator;
				for (pIterator = p.begin(); pIterator < p.end(); ++pIterator) {
					if (pIterator->first == pairsIterator->first)
						pIterator->second = DONE;
				}
				break ;
			}
		}
	}

	insertLastNumbers(s, p);
	_vector = s;
}
/* <----------------------------> */

void PmergeMe::sortContainers() {
	std::string containersNames[2] = { "std::list", "std::vector" };
	void (PmergeMe::*sort[2])() = { &PmergeMe::sortList, &PmergeMe::sortVector };

	for (int i = 0; i < 2; ++i) {
		std::clock_t start, end;

		start = std::clock();
		(this->*sort[i])();
		end = std::clock();

		printTimeSpent(static_cast<double>(end - start), containersNames[i]);
	}
}
/* <----------------------------> */
