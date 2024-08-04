/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:47:56 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 03:37:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

# include "Zombie.hpp"

Zombie*	newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif