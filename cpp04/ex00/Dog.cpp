/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:46 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/16 23:55:04 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Dogs go WOOF" << std::endl;
}
		
Dog::Dog() : Animal("Dog")
{
	std::cout << "Default dog constructor called" << std::endl;

}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Parametrised dog constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}