/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:41 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/12 02:29:28 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	if (_energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
		return ;
	}
	_energyPoints -=1;
	std::cout << "ClapTrap " << _name 
	<< " attacks " << target 
	<< ", causing " << _attackDamage 
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " has been attacked! \n" 
	<< amount << " damage taken\n" 
	<< "Hitpoints remaining: " << _hitPoints 
	<< "\nEnergy points remaining: " << _energyPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	if (_energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -=1;
	std::cout << "ClapTrap " << _name 
	<< " Repaired " << amount << " hitpoints" 
	<< "\nHitpoints remaining: " << _hitPoints
	<< "\nEnergy points remaining: " << _energyPoints << std::endl;
}

void	ClapTrap::showStatus() const
{
	std::cout << "ClapTrap: " << _name 
	<< "\nHitpoints remaining: " << _hitPoints
	<< "\nEnergy points remaining: " << _energyPoints
	<< "\nAttack damage: " << _attackDamage << std::endl;
}

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterised constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other) 
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}