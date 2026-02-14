/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 05:09:03 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:39:10 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::showStatus() const
{
	std::cout << "DiamondTrap: " << getName() 
	<< "\nHitpoints remaining: " << getHP()
	<< "\nEnergy points remaining: " << getEP()
	<< "\nAttack damage: " << getAD() << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name
	<< "\nClapTrap name: " << ClapTrap::getName() << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	setHP(100);
	setEP(50);
	setAD(30);
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	setHP(100);
	setEP(50);
	setAD(30);
	std::cout << "Parameterised DiamondTrap constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		setName(other.getName());
		std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other.getName())
{
	setHP(100);
	setEP(50);
	setAD(30);
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
