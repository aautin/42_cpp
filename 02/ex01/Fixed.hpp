/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:11 by aautin            #+#    #+#             */
/*   Updated: 2024/08/10 03:18:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

class Fixed
{
	private:
		int					value;
		static const int	fractionalBitsNb = 8;

	public:
		/* OCCF */
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);

		Fixed				&operator=(Fixed const &other);

		Fixed(int const value);
		Fixed(float const value);

		/* Others */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const; 
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed& fixed);

#endif