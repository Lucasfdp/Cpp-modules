/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:39 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/16 23:07:11 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::makeSound() const
{
	std::cout << "Hmmmm idk what animal this is so neigh?" << std::endl;
}

void	Animal::setType(const std::string &value)
{
	_type = value;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
		
Animal::Animal() : _type("Default")
{
	std::cout << "Default animal constructor called" << std::endl;

}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Parametrised animal constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other.getType();
		std::cout << "Animal copy assignment operator called" << std::endl;
	}
	return (*this);
}

Animal::Animal(const Animal &other) : _type(other.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}