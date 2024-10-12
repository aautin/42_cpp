/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:21:33 by aautin            #+#    #+#             */
/*   Updated: 2024/10/12 15:51:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
# include <list>
# include <vector>

class PmergeMe
{
	public:
		/* >------ Cons/Destructors ------< */
		PmergeMe() : _size(0) {}
		PmergeMe(PmergeMe const & other)
		: _list(other._list), _vector(other._vector), _size(other._size) {}
		~PmergeMe() {}
		
		/* >------ Overloads ------< */
		PmergeMe&	operator=(PmergeMe const & other) {
			_list = other._list;
			_size = other._size;
			_vector = other._vector;
		}

		/* >------ Utils ------< */
		void		printTimeSpent(double time, std::string containerName);

		/* >------ Operations on containers ------< */
		void		addNumber(int number);

		/* >------ Sorting ------< */
		void		sortList();
		void		sortVector();
		void		sortContainers();

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		int					_size;
};

#endif