/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 07:05:51 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/22 06:02:03 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}

		_name = other._name;
		for (int i = 0; i < 4; ++i)
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (_inventory[i])
			delete _inventory[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
