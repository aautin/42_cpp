/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:28 by aautin            #+#    #+#             */
/*   Updated: 2024/08/23 13:29:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# define _MATERIAS_SIZE	4

# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		/* >------ Cons/Destructors ------< */
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);

		/* >------ Others ------< */
		void			learnMateria(AMateria *materia);
		AMateria*		createMateria(std::string const & type);

	private:
		AMateria	*_materias[_MATERIAS_SIZE];
};

#endif