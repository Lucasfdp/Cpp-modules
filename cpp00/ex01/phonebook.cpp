/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:09:06 by luferna3          #+#    #+#             */
/*   Updated: 2025/12/29 04:37:37 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//constructor

PhoneBook::PhoneBook()
{
	index = 0;
	numContacts = 0;
}

void PhoneBook::addContact()
{
    std::string input;

    // First Name
    do
    {
        std::cout << "First name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    contacts[index].setFirstName(input);

    // Last Name
    do
    {
        std::cout << "Last name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    contacts[index].setLastName(input);

    // Nickname
    do
    {
        std::cout << "Nickname: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    contacts[index].setNickname(input);

    // Phone Number
    do
    {
        std::cout << "Phone number: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    contacts[index].setPhoneNumber(input);

    // Darkest Secret
    do
    {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    contacts[index].setDarkestSecret(input);

    // Update index and numContacts
    index = (index + 1) % 8;
    if (numContacts < 8)
        numContacts++;

    std::cout << "Contact added successfully!" << std::endl;
}


std::string PhoneBook::truncate(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool PhoneBook::isNumeric(const std::string &str) const
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::searchContacts() const
{
    // // helper to truncate strings > 10 chars
    // std::string truncate(const std::string &str) {
    //     if (str.length() > 10)
    //         return str.substr(0, 9) + ".";
    //     return str;
    // }

    if (numContacts == 0) {
        std::cout << "PhoneBook empty" << std::endl;
        return;
    }

    // header
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname"
              << std::endl;

    for (int i = 0; i < numContacts; i++) {
        std::cout << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname())
                  << std::endl;
    }

    std::cout << "Enter an index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    int num = 0;
    std::stringstream ss(input);
    if (!(ss >> num) || num <= 0 || num > numContacts) {
        std::cout << "Please enter a valid index" << std::endl;
        return;
    }

    // display full contact info
    num--;
    std::cout << "First Name: " << contacts[num].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[num].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[num].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[num].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[num].getDarkestSecret() << std::endl;
}