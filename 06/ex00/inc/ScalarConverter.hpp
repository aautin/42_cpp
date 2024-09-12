/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:32:58 by aautin            #+#    #+#             */
/*   Updated: 2024/09/12 18:39:37 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

# include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string const &literal);
};

#endif