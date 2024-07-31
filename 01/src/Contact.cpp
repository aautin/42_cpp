/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:32:38 by aautin            #+#    #+#             */
/*   Updated: 2024/07/31 02:58:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

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
void Contact::setFirstName(std::string &firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(std::string &lastName)
{
	this->lastName = lastName;
}
void Contact::setNickName(std::string &nickName)
{
	this->nickName = nickName;
}
void Contact::setPhoneNumber(__int64_t &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
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
__int64_t Contact::getPhoneNumber() const
{
	return phoneNumber;
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
