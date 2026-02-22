/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:46 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:19:08 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Dogs go WOOF" << std::endl;
}

void	Dog::setBrainIdea(int index, const std::string& idea)
{
	_Brain->setIdea(index, idea);
}

std::string	Dog::getBrainIdea(int index) const
{
	return (_Brain->getIdea(index));
}

Dog::Dog() : Animal("Dog")
{
	_Brain = new Brain();
	std::cout << "Default dog constructor called" << std::endl;

}

Dog::Dog(std::string type) : Animal(type)
{
	_Brain = new Brain();
	std::cout << "Parametrised dog constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _Brain;
		_Brain = new Brain(*other._Brain);
		std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_Brain = new Brain(*other._Brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destructor called" << std::endl;
}