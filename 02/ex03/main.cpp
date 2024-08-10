/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:11:17 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 17:23:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(4.5, 4.2);
	Point	b(a);
	Point	c = b;
	Point	point(0.2, 0.2);

	if (bsp(a, b, c, point) == TRUE)
		std::cout << "In!" << std::endl;
	else
		std::cout << "Out!" << std::endl;
	return 0;
}
