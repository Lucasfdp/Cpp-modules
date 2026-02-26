/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 05:30:33 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/26 22:06:42 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{

}

AMateria::AMateria(std::string const & type) : _type(type)
{

}

AMateria::AMateria(const AMateria &other) : _type(other.getType())
{

}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		setType(other._type);
	return (*this);
}

AMateria::~AMateria()
{

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
