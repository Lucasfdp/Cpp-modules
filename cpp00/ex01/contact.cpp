/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 06:50:42 by luferna3          #+#    #+#             */
/*   Updated: 2025/12/28 21:53:02 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//setters

void	Contact::setFirstName(const std::string &value)
{
	firstName = value;
}

void	Contact::setLastName(const std::string &value)
{
	lastName = value;
}

void	Contact::setNickname(const std::string &value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(const std::string &value)
{
	phoneNumber = value;
}

void	Contact::setDarkestSecret(const std::string &value)
{
	darkestSecret = value;
}

//getters

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

//constructor

Contact::Contact()
{
	
}