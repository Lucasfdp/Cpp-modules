/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:25:43 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/03 05:54:56 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
: name(newName), weapon(0)
{
	
}

void	HumanB::setWeapon(Weapon& Weapon)
{
	weapon = &Weapon;
}

void	HumanB::attack()
{
	if (weapon == 0)
		return ;
	std::cout << name << " attacks with their "
	<< weapon->getType() << std::endl;
}

HumanB::~HumanB(void)
{
	
}