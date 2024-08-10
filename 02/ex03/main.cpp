/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:11:17 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 08:44:24 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point const a, b, c;
	Point const point;

	if (bsp(a, b, c, point) == TRUE)
		std::cout << "In!" << std::endl;
	else
		std::cout << "Out!" << std::endl;
	return 0;
}
