/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:02:11 by aautin            #+#    #+#             */
/*   Updated: 2024/08/09 15:39:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits_nb = 8;

	public:
		/* OCCF */
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed &operator=(Fixed const &other);

		/* Others */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif