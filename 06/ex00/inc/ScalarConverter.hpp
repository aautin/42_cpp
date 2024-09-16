/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:32:58 by aautin            #+#    #+#             */
/*   Updated: 2024/09/16 16:29:05 by aautin           ###   ########.fr       */
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

class ScalarConverter
{
	public:
		static void	convert(std::string &literal);

		class ConverterException : public std::exception {};
};

#endif