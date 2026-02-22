/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 05:30:33 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/22 02:20:45 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{
	//std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	//std::cout << "AMateria parametrised constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other.getType())
{
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		setType(other._type);
		//std::cout << "AMateria copy assignment operator called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor called" << std::endl;
}
		
std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::setType(const std::string &newType)
{
	_type = newType;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Invalid AMateria" << std::endl;
}
