/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:10:29 by aautin            #+#    #+#             */
/*   Updated: 2024/08/12 15:18:57 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x, y;

	public:
		/* OCCF */
		Point();
		Point(float const x, float const y);
		Point(Point const &operand);
		Point	&operator=(Point &operand);
		~Point();

		/* Others */
		void	print(std::string name) const;
};

#endif