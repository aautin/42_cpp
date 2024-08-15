/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:10:07 by aautin            #+#    #+#             */
/*   Updated: 2024/08/12 15:31:23 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* OCCF */
Point::Point() : x(0), y(0) {}
Point::~Point() {}
Point::Point(float const x, float const y) : x(x), y(y) {}
Point::Point(Point const &operand) : x(operand.x), y(operand.y) {}
Point	&Point::operator=(Point &operand)
{
	this->x = operand.x;
	this->y = operand.y;
	return *this;
}

/* Others */
void	Point::print(std::string name) const
{
	std::cout << name << " : " << this->x.toFloat() << "x";
	std::cout << ", " << this->y.toFloat() << "y." << std::endl;
}
