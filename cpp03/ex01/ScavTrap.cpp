/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:38 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/12 06:37:11 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	unsigned int EP = getEP();
	unsigned int AD = getAD();
	
	if (AD == 0)
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

// void	ScavTrap::takeDamage(unsigned int amount)
// {
// 	unsigned int HP = getHP();
// 	unsigned int EP = getEP();
	
// 	if (HP == 0)
// 	{
// 		std::cout << "ScavTrap " << getName << " is already dead." << std::endl;
// 		return;
// 	}
// 	if (amount > HP)
// 		setHP(0);
// 	else
// 		_hitPoints -= amount;
// 	std::cout << "ScavTrap " << getName << " has been attacked! \n" 
// 	<< amount << " damage taken\n" 
// 	<< "Hitpoints remaining: " << _hitPoints 
// 	<< "\nEnergy points remaining: " << _energyPoints << std::endl;
// }

// void	ScavTrap::beRepaired(unsigned int amount)
// {
// 	unsigned int HP = getHP();
// 	unsigned int EP = getEP();
	
// 	if (HP == 0)
// 	{
// 		std::cout << "ScavTrap " << getName << " is already dead." << std::endl;
// 		return ;
// 	}
// 	if (EP == 0)
// 	{
// 		std::cout << "ScavTrap " << getName << " has no energy left." << std::endl;
// 		return ;
// 	}
// 	setHP(HP + amount);
// 	setEP(EP - 1);
// 	std::cout << "ScavTrap " << getName 
// 	<< " Repaired " << amount << " hitpoints" 
// 	<< "\nHitpoints remaining: " << HP
// 	<< "\nEnergy points remaining: " << EP << std::endl;
// }
void	ScavTrap::showStatus() const
{
	std::cout << "ScavTrap: " << getName() 
	<< "\nHitpoints remaining: " << getHP()
	<< "\nEnergy points remaining: " << getEP()
	<< "\nAttack damage: " << getAD() << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!_guardMode)
	{
		_guardMode = 1;
		std::cout << "ScavTrap " << getName() << " is in Gate keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " is already in Gate keeper mode." << std::endl;
}
		
ScavTrap::ScavTrap() : ClapTrap(), _guardMode(0)
{
	setHP(100);
	setEP(50);
	setAD(20);
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardMode(0)
{
	setHP(100);
	setEP(50);
	setAD(20);
}
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_guardMode = other._guardMode;
		setName(other.getName());
		setHP(other.getHP());
		setEP(other.getEP());
		setAD(other.getAD());
		std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	_guardMode = other._guardMode;
	setName(other.getName());
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());
}

ScavTrap::~ScavTrap()
{
	
}
