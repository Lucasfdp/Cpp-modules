/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:38 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:48:16 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// void	FragTrap::attack(const std::string& target)
// {
// 	unsigned int EP = getEP();
// 	unsigned int AD = getAD();
	
// 	if (getHP() == 0)
// 	{
// 		std::cout << "FragTrap " << getName() << " is already dead." << std::endl;
// 		return ;
// 	}
// 	if (EP < 1)
// 	{
// 		std::cout << "FragTrap " << getName() << " is out of energy." << std::endl;
// 		return ;
// 	}
// 	setEP(EP - 1);
// 	std::cout << "FragTrap " << getName() 
// 	<< " attacks " << target 
// 	<< ", causing " << AD 
// 	<< " points of damage!" << std::endl;
// }

void	FragTrap::showStatus() const
{
	std::cout << "FragTrap: " << getName() 
	<< "\nHitpoints remaining: " << getHP()
	<< "\nEnergy points remaining: " << getEP()
	<< "\nAttack damage: " << getAD() << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Would you care for the highest of fives?" << std::endl;
}


FragTrap::FragTrap() : ClapTrap()
{
	setHP(100);
	setEP(100);
	setAD(30);
	std::cout << "Default FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHP(100);
	setEP(100);
	setAD(30);
	std::cout << "Parameterised FragTrap constructor called" << std::endl;
}
FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap Copy assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
