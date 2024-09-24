/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:52:51 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 14:21:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <vector>

template <typename T>
int	easyfind(T const & array, int index) {
	std::vector<int> const &castArray = static_cast<std::vector<int> >(array);
	for (std::vector<int>::const_iterator it = castArray.begin(); it != castArray.end(); ++it) {
		if (*it == index)
			return it - castArray.begin(); /* Return iterator<->origin adresses' gap */
	}
	throw std::exception();
}

#endif