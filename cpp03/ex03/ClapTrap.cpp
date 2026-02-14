/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:41 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:37:13 by luferna3         ###   ########.fr       */
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

std::string	ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHP() const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEP() const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAD() const
{
	return (_attackDamage);
}

void	ClapTrap::setName(const std::string &value)
{
	_name = value;
}

void	ClapTrap::setHP(const unsigned int &value)
{
	_hitPoints = value;
}

void	ClapTrap::setEP(const unsigned int &value)
{
	_energyPoints = value;
}

void	ClapTrap::setAD(const unsigned int &value)
{
	_attackDamage = value;
}

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterised ClapTrap constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other) 
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}