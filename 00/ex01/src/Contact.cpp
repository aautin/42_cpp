/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:32:38 by aautin            #+#    #+#             */
/*   Updated: 2024/08/02 00:14:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "userInterface.hpp"

#include <iostream>

/* Constructor-Destructor */
Contact::Contact(void)
{
	firstName = "Rick";
	lastName = "Astley";
	nickName = "Dick Spatsley";
	phoneNumber = 7271987;
	darkestSecret = "Never Gonna Give You Up";
}
Contact::~Contact(void) {}


/* Setters */
void Contact::setFirstName(std::string &newFirstName)
{
	this->firstName = newFirstName;
}
void Contact::setLastName(std::string &newLastName)
{
	this->lastName = newLastName;
}
void Contact::setNickName(std::string &newNickName)
{
	this->nickName = newNickName;
}
void Contact::setDarkestSecret(std::string &newDarkestSecret)
{
	this->darkestSecret = newDarkestSecret;
}
void Contact::setPhoneNumber(long newPhoneNumber)
{
	this->phoneNumber = newPhoneNumber;
}


/* Getters */
std::string Contact::getFirstName() const
{
	return firstName;
}
std::string Contact::getLastName() const
{
	return lastName;
}
std::string Contact::getNickName() const
{
	return nickName;	
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
long Contact::getPhoneNumber() const
{
	return phoneNumber;
}


/* Others */
void	Contact::searchContact(int contactIndex) const
{
	std::cout << "|         " << contactIndex << "|";
	printField(this->getFirstName());
	std::cout << "|";
	printField(this->getLastName());
	std::cout << "|";
	printField(this->getNickName());
	std::cout << "|" << std::endl;
}
void	Contact::printContact() const
{
	
}