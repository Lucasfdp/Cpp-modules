/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:32 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/12 06:36:52 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	// ClapTrap	brian;
	// ClapTrap steve("Steve");
	// steve.attack("Jeff");
	// steve.takeDamage(5);
	// steve.beRepaired(100);
	// ClapTrap	jerry(steve);
	// steve.showStatus();
	// jerry.showStatus();
	ScavTrap	scav1("Scavman");
	scav1.attack("Jeff");
	ScavTrap scav2("Jeff2");
	ScavTrap	scav3(scav1);
	scav2 = scav1;
	scav1.showStatus();
	scav2.showStatus();
	scav3.showStatus();
	return 0;
}
