/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:48:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/01 03:41:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

static void printContactVariables(Contact *contact)
{
	if (contact == NULL) {
		std::cout << ">>----NULL-----<<" << std::endl;
		return ;
	}

	std::cout << ">>---------------" << std::endl;
	std::cout << "Firstname : " << contact->getFirstName() << std::endl;
	std::cout << "Lastname : " << contact->getLastName() << std::endl;
	std::cout << "Nickname : " << contact->getNickName() << std::endl;
	std::cout << "Phone number : " << contact->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact->getDarkestSecret() << std::endl;
	std::cout << "---------------<<" << std::endl;
}

int	main(void)
{
	PhoneBook	phoneBook;

	for (int i = 0; i < MAX_CONTACTS_NBR + 2; i++)
		phoneBook.setContact(new Contact());

	for (int i = 0; i < MAX_CONTACTS_NBR; i++) {
		phoneBook.getContact(i)->setPhoneNumber(i);
		printContactVariables(phoneBook.getContact(i));
	}
}
