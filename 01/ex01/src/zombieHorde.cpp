/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:38:10 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:06:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>

#include "Zombie.h"
#include "Zombie.hpp"

#include <sstream>
#include <string>

static std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::string nameIndex = name + " " + intToString(i);
		horde[i].Zombie::setName(nameIndex);
	}

	return horde;
}
