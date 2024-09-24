/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:52:51 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 14:48:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <vector>

template <typename T>
int	easyfind(T const & array, int value) {
	std::vector<int>::const_iterator it = std::find(array.begin(), array.end(), value);
	
	if (it == array.end())
		throw std::exception();

	return it - array.begin(); /* Return iterator<->origin adresses' gap */
}

#endif