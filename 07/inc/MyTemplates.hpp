/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTemplates.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:44:35 by aautin            #+#    #+#             */
/*   Updated: 2024/09/23 15:58:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYTEMPLATES_HPP
# define MYTEMPLATES_HPP

template <typename Type> class MyTemplates
{
	public:
		static void	swap(Type& a, Type& b) {
			Type temp = a;
			a = b;
			b = temp;
		}
		static Type	min(Type a, Type b) { return (a < b) ? a : b; }
		static Type	max(Type a, Type b) { return (a > b) ? a : b; }
};

#endif