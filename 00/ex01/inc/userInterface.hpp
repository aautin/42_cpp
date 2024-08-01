/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:19:42 by aautin            #+#    #+#             */
/*   Updated: 2024/08/02 00:20:02 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

# include <string>

# define EDGE "\033[33m*********************************************\033[0m"
# define FIELD_SIZE 10

void 		printField(std::string field);
void		printLine(char const *line);
void		printInvalid(int trialNumber, char const *invalidType);
std::string	readLine(char *prompt);

#endif