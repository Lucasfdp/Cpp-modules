/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:01:05 by luferna3          #+#    #+#             */
/*   Updated: 2025/12/29 00:34:37 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
    int numContacts;

    std::string truncate(const std::string &str) const;
    bool isNumeric(const std::string &str) const;

public:
    PhoneBook();

    void addContact();
    void searchContacts() const;
};

#endif
