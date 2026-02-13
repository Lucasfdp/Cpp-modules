/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:32 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/13 04:52:52 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	FragTrap	Frag1("Scavman");
	Frag1.attack("Jeff");
	// FragTrap Frag2("Jeff2");
	// FragTrap	Frag3(Frag1);
	// Frag1.guardGate();
	// Frag2.guardGate();
	// Frag3.guardGate();
	// Frag2 = Frag1;
	// Frag1.showStatus();
	// Frag2.showStatus();
	// Frag3.showStatus();
	Frag1.hiFive();
	return 0;
}
