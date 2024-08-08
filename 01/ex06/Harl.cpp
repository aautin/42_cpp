/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:02:07 by aautin            #+#    #+#             */
/*   Updated: 2024/08/08 21:35:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

/* Constructor-Destructor */
Harl::Harl(int filter) {

	for (size_t i = 0; i < 4; i++)
		msgsStatus[i] = OFF;
	switch (filter) {
		case 1:
			msgsStatus[0] = ON;
		case 2:
			msgsStatus[1] = ON;
		case 3:
			msgsStatus[2] = ON;
		case 4:
			msgsStatus[3] = ON;
	}
	
	msgsNames[0] = "DEBUG";
	msgsFunctions[0] = &Harl::debug;

	msgsNames[1] = "INFO";
	msgsFunctions[1] = &Harl::info;

	msgsNames[2] = "WARNING";
	msgsFunctions[2] = &Harl::warning;

	msgsNames[3] = "ERROR";
	msgsFunctions[3] = &Harl::error;
}
Harl::~Harl() {}


/* Private */
void	Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl;
}
void	Harl::info( void )
{
	std::cout << INFO_MSG << std::endl;
}
void	Harl::warning( void )
{
	std::cout << WARNING_MSG << std::endl;
}
void	Harl::error( void )
{
	std::cout << ERROR_MSG << std::endl;
}


/* Public */
void		Harl::complain( std::string level )
{
	for (size_t i = 0; i < 4; i++)
		if (level == msgsNames[i] && msgsStatus[i] == ON)
			(this->*msgsFunctions[i])();
}
