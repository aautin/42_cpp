/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by aautin            #+#    #+#             */
/*   Updated: 2024/08/07 23:56:21 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <string>

# define FAILURE	1
# define SUCCESS	0

class File
{
	private:
		std::string	&name;
		std::string	content;

	public:
		/* Constructor-Destructor */
		File(std::string &name);
		~File();

		/* Others */
		std::string	&getName() const;
		void		replace(std::string const &target, std::string const &replacement);
		bool		load(std::string const &sourceFileName);
		// void		stream(std::string const &destinationFileName) const ;
};

#endif