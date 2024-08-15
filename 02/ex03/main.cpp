/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:11:17 by aautin            #+#    #+#             */
/*   Updated: 2024/08/12 15:41:50 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

static Point *getPoints(int argc, char **argv)
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

	Point*	points = new Point[4] {
		Point(aX, aY),
		Point(bX, bY),
		Point(cX, cY),
		Point(pX, pY)
	};
	return points;
}

bool bsp( Point const a, Point const b, Point const c, Point const point);
int	main(int argc, char **argv)
{
	Point	*points = getPoints(argc, argv);
	if (points == NULL)
		return 0;

	points[0].print("a"), points[1].print("b");
	points[2].print("c"), points[3].print("point");

	if (bsp(points[0], points[1], points[2], points[3]) == true)
		std::cout << "In!" << std::endl;
	else
		std::cout << "Out!" << std::endl;

	return 0;
}
