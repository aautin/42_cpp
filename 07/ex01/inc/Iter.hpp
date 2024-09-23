/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:44:35 by aautin            #+#    #+#             */
/*   Updated: 2024/09/23 17:12:37 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename Type>
void	iter(Type* table, int tableSize, void (*f)(Type &it)) {
	for (int i = 0; i < tableSize; i++)
		f(table[i]);
}

#endif