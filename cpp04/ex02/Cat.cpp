/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:43 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:42:16 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound() const
{
	std::cout << "Cats go MEOW" << std::endl;
}

void	Cat::setBrainIdea(int index, const std::string& idea)
{
	_Brain->setIdea(index, idea);
}

std::string	Cat::getBrainIdea(int index) const
{
	return (_Brain->getIdea(index));
}

Cat::Cat() : Animal("Cat")
{
	_Brain = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;

}

Cat::Cat(std::string type) : Animal(type)
{
	_Brain = new Brain();
	std::cout << "Parametrised Cat constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _Brain;
		_Brain = new Brain(*other._Brain);
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_Brain = new Brain(*other._Brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "Cat destructor called" << std::endl;
}