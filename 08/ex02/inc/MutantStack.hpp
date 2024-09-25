/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:35:46 by aautin            #+#    #+#             */
/*   Updated: 2024/09/25 20:50:44 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <deque>

template <typename Content, class Container = std::deque<Content> >
class MutantStack : public std::stack<Content, Container>
{
	public:
		/* >------ Cons/Destructors ------< */
		MutantStack() {}
		MutantStack(MutantStack const & other)
		: std::stack<Content, Container>(other) {}
		~MutantStack() {}
		
		/* >------ Overloads ------< */
		MutantStack&	operator=(MutantStack const & other) {
			this->std::stack<Content, Container>::operator=(other);
			return *this;
		}
};

#endif