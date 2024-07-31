/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/07/31 03:08:30 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

static void printContactVariables(Contact const &contact)
{
	std::cout << ">>---------------" << std::endl;
	std::cout << "Firstname : " << contact.getFirstName() << std::endl;
	std::cout << "Lastname : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickName() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.getDarkestSecret() << std::endl;
	std::cout << "---------------<<" << std::endl;
}

int	main(void)
{
	/* Create contact and print its variables */
	Contact randomContact;
	printContactVariables(randomContact);

	/* Set a new secret to the contact */
	std::string newSecret = "New secret";
	randomContact.setDarkestSecret(newSecret);
	printContactVariables(randomContact);
}
