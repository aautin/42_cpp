/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:35:46 by aautin            #+#    #+#             */
/*   Updated: 2024/09/24 16:39:50 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename ContentType>
class MutantStack : public std::stack<ContentType, Container>
{
	public:
		/* >------ Cons/Destructors ------< */
		MutantStack();
		MutantStack(MutantStack const & other);
		~MutantStack();
		
		/* >------ Overloads ------< */
		MutantStack&	operator=(MutantStack const & other);
};

#endif