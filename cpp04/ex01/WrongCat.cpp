/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:08:54 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 00:12:13 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat go MEOW" << std::endl;
}
		
WrongCat::WrongCat() : WrongAnimal("Cat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;

}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "Parametrised WrongCat constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		std::cout << "WrongCat copy assignment operator called" << std::endl;
	}
	return (*this);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}