/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:43 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 00:12:27 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound() const
{
	std::cout << "Cats go MEOW" << std::endl;
}
		
Cat::Cat() : Animal("Cat")
{
	std::cout << "Default cat constructor called" << std::endl;

}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Parametrised cat constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}