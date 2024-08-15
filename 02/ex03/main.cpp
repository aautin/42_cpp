/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:11:17 by aautin            #+#    #+#             */
/*   Updated: 2024/08/15 22:17:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

static void	printPoints(Point const a, Point const b, Point const c, Point const p)
{
	a.print("a");
	b.print("b");
	c.print("c");
	p.print("p");
}

bool bsp(Point const a, Point const b, Point const c, Point const p);
int	main(int argc, char **argv)
{
	float aX, aY, bX, bY, cX, cY, pX, pY;
	if (argc >= 9) {
		aX = strtof(argv[1], NULL), aY = strtof(argv[2], NULL);
		bX = strtof(argv[3], NULL), bY = strtof(argv[4], NULL);
		cX = strtof(argv[5], NULL), cY = strtof(argv[6], NULL);
		pX = strtof(argv[7], NULL), pY = strtof(argv[8], NULL);
	}
	else {
		aX = 4.16, aY = 2.1;
		bX = 1.9, bY = 7.6;
		cX = 8, cY = 0.7;
		pX = 1.2, pY = 7.2;
	}

	Fixed number((const float) 0.99609375);
	std::cout << number.toFloat() << std::endl;
	number++;
	std::cout << number.toFloat() << std::endl;

	Point a(aX, aY);
	Point b(bX, bY);
	Point c(cX, cY);
	Point p(pX, pY);

	printPoints(a, b, c, p);

	if (bsp(a, b, c, p) == true)
		std::cout << "In!" << std::endl;
	else
		std::cout << "Out!" << std::endl;

	return 0;
}
