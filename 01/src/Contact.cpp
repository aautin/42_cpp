/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:32:38 by aautin            #+#    #+#             */
/*   Updated: 2024/07/30 21:13:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructed" << std::endl;
	
}

Contact::Contact(std::string const &firstName, std::string const &lastName,
				std::string const &nickName, std::string const &phoneNumber,
				std::string const &darkestSecret)
{
	std::cout << "Contact constructed but differently" << std::endl;
	
}

Contact::~Contact(void)
{
	std::cout << "Contact destructed" << std::endl;
}