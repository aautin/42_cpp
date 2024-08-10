/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:10:07 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 17:21:27 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* OCCF */
Point::Point() : x(0), y(0) {}
Point::~Point() {}
Point::Point(float const x, float const y) : x(x), y(y) {}
Point::Point(Point const &operand) : x(operand.x), y(operand.y) {}
Point	&Point::operator=(Point const &operand)
{
	*this = Point(operand);
	return *this;
}
