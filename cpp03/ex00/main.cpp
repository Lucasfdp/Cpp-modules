/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:32 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/12 02:45:45 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	ClapTrap a("A");
	ClapTrap* b = &a;
	b->attack("target");

	a.showStatus();
	return 0;
}
