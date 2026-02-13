/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:38 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/13 03:37:13 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	unsigned int EP = getEP();
	unsigned int AD = getAD();
	
	if (getHP() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is already dead." << std::endl;
		return ;
	}
	if (EP < 1)
	{
		std::cout << "ScavTrap " << getName() << " is out of energy." << std::endl;
		return ;
	}
	setEP(EP - 1);
	std::cout << "ScavTrap " << getName() 
	<< " attacks " << target 
	<< ", causing " << AD 
	<< " points of damage!" << std::endl;
}

void	ScavTrap::showStatus() const
{
	std::cout << "ScavTrap: " << getName() 
	<< "\nHitpoints remaining: " << getHP()
	<< "\nEnergy points remaining: " << getEP()
	<< "\nAttack damage: " << getAD() << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!getGM())
	{
		setGM(true);
		std::cout << "ScavTrap " << getName() << " is in Gate keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " is already in Gate keeper mode." << std::endl;
}

bool	ScavTrap::getGM(void) const
{
	return (_guardMode);
}

void	ScavTrap::setGM(const bool &value)
{
	_guardMode = value;
}

ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false)
{
	setHP(100);
	setEP(50);
	setAD(20);
	std::cout << "Default ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardMode(false)
{
	setHP(100);
	setEP(50);
	setAD(20);
	std::cout << "Parameterised ScavTrap constructor called" << std::endl;
}
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		setGM(other.getGM());
		std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _guardMode(other.getGM())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
