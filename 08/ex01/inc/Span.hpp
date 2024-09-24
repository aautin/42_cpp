/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:40 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 15:10:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# define DEFAULT_MAX_SIZE 10

# include <vector>

class Span
{
	public:
		/* >------ Cons/Destructors ------< */
		Span();
		Span(unsigned int N);
		Span(Span const & other);
		~Span();
		
		/* >------ Other ------< */
		Span	&operator=(Span const & other);
		int		shortestSpan() const;
		int		longestSpan() const;

		/* Set/Getters */
		void	add(int value);
		int		getMaxSize() const;

	private:
		std::vector<int>	_storage;
		unsigned int		_maxSize;
};

#endif