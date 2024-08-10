/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:11 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 08:47:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBitsNb = 8;

	public:
		/* OCCF */
		Fixed();
		~Fixed();
		Fixed(Fixed const &operand);


		Fixed(int const value);
		Fixed(float const value);

		/* Others */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const; 

		static Fixed		&min(Fixed &it1, Fixed &it2);
		static const Fixed	&min(Fixed const &it1, Fixed const &it2);
		static Fixed		&max(Fixed &it1, Fixed &it2);
		static const Fixed	&max(Fixed const &it1, Fixed const &it2);


		/* Overloads */
		Fixed	&operator=(Fixed const &operand);

		Fixed	operator+(Fixed const &operand);
		Fixed	operator-(Fixed const &operand);
		Fixed	operator*(Fixed const &operand);
		Fixed	operator/(Fixed const &operand);

		bool	operator<(Fixed const &operand);
		bool	operator<=(Fixed const &operand);
		bool	operator>(Fixed const &operand);
		bool	operator>=(Fixed const &operand);
		bool	operator==(Fixed const &operand);
		bool	operator!=(Fixed const &operand);

		float	operator++();
		float	operator--();
		float	operator++(int);
		float	operator--(int);
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed& fixed);


#endif