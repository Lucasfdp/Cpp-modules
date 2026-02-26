/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:44:20 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/26 22:10:11 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (size_t i = 0; i < 4; i++)
		_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_templates[i])
				delete _templates[i];
			_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_templates[i] != NULL)
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* newMat)
{
	if (newMat == NULL)
		return ;
	for (size_t i = 0; i < 4; ++i)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = newMat->clone();
			delete newMat;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (_templates[i] != NULL && _templates[i]->getType() == type)
		{
			return (_templates[i]->clone());
		}
	}
	return (NULL);
}

