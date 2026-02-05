/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:21:00 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/03 05:54:39 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon)
: name(newName), weapon(newWeapon)
{
	
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their "
	<< weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	
}