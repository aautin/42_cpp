/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:32:58 by aautin            #+#    #+#             */
/*   Updated: 2024/09/19 15:22:52 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <exception>
# include <string>

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FLOAT_EXCEPTION,
	DOUBLE_EXCEPTION,
	NONE
}	t_type;

typedef struct s_scalar {
	char	c;
	int		i;
	float	f;
	double	d;
}	t_scalar;

class ScalarConverter
{
	public:
		static void	convert(std::string &literal);

		class Exception : public std::exception {};
};

#endif