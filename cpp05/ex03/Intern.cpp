/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 05:56:39 by luferna3          #+#    #+#             */
/*   Updated: 2026/04/25 01:28:04 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

static AForm *makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm *makePresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string& type, const std::string& target)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(*makers[3])(const std::string&) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (type == names[i])
        {
            std::cout << "Intern creates " << type << std::endl;
            return makers[i](target);
        }
    }
    std::cout << "Intern couldn't create form: unknown type \"" << type << "\"" << std::endl;
    return NULL;
}