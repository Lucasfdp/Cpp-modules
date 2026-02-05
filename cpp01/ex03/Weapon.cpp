/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 04:48:04 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/03 05:02:50 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(const std::string& newWeapon)
{
	type = newWeapon;
	return ;
}

Weapon::Weapon(std::string newWeapon)
{
	type = newWeapon;
}

Weapon::~Weapon()
{
	
}