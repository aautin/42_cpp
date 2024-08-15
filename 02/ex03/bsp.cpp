/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:41:39 by aautin            #+#    #+#             */
/*   Updated: 2024/08/15 23:54:16 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

typedef Point Vector;
bool	bsp( Point const a, Point const b, Point const c, Point const p)
{
	/* Calculate a vector from 2 points, A(x, y) B(x', y') : AB = (x' - x, y' - y) */
	Vector AB(b.getX() - a.getX(), b.getY() - a.getY());
	Vector AP(p.getX() - a.getX(), p.getY() - a.getY());
	
	Vector BC(c.getX() - b.getX(), c.getY() - b.getY());
	Vector BP(p.getX() - b.getX(), p.getY() - b.getY());

	Vector CA(a.getX() - c.getX(), a.getY() - c.getY());
	Vector CP(p.getX() - c.getX(), p.getY() - c.getY());

	AB.print("AB");

	/* To be continued (compare vectors all together) ... */

	return true;
}
