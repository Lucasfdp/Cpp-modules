/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:26:37 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:29:25 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

const std::string	Brain::getIdea(int index) const
{
	return (_ideas[index]);
}

const std::string*	Brain::getAllIdeas(void) const
{
	return (_ideas);
}

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Empty";
	std::cout << "Default brain constructor called" << std::endl;

}

Brain::Brain(const std::string ideas[], int amount)
{
	for (int i = 0; i < 100; i++)
	{
		if (i < amount)
			_ideas[i] = ideas[i];
		else
			_ideas[i] = "Empty";
	}
	std::cout << "Parametrised brain constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
		std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return (*this);
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
