/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:02:41 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 00:06:43 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound() const
{
	std::cout << "Hmmmm idk what WrongAnimal this is so neigh?" << std::endl;
}

void	WrongAnimal::setType(const std::string &value)
{
	_type = value;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}
		
WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;

}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Parametrised WrongAnimal constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other.getType();
		std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	}
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other.getType())
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}