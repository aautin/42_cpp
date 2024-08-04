/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:31:33 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 02:47:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		/* Constructor-Destructor */
		Zombie(void);
		~Zombie(void);

		void		setName(std::string const &name);
		std::string	getName( void );
		void		announce( void );
};

#endif