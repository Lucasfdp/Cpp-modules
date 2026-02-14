/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:20:32 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:57:09 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
	std::cout << "\n=== CLAPTRAP TESTS ===\n";
	ClapTrap a("A");
	ClapTrap b;                     // default
	ClapTrap c(a);                  // copy constructor
	b = a;                          // assignment operator

	a.attack("Target1");
	a.takeDamage(5);
	a.beRepaired(3);
	// a.showStatus();
	// b.showStatus();
	// c.showStatus();

	std::cout << "\n=== SCAVTRAP TESTS ===\n";
	ScavTrap s1("S1");
	ScavTrap s2;                    // default
	ScavTrap s3(s1);                // copy constructor
	s2 = s1;                        // assignment

	s1.attack("Enemy1");
	s1.takeDamage(10);
	s1.beRepaired(5);
	s1.guardGate();                 // specific ability
	// s1.showStatus();
	// s2.showStatus();
	// s3.showStatus();

	std::cout << "\n=== FRAGTRAP TESTS ===\n";
	FragTrap f1("F1");
	FragTrap f2;
	FragTrap f3(f1);
	f2 = f1;

	f1.attack("EnemyF");
	f1.takeDamage(15);
	f1.beRepaired(10);
	f1.highFivesGuys();             // specific ability
	// f1.showStatus();
	// f2.showStatus();
	// f3.showStatus();

	std::cout << "\n=== DIAMONDTRAP TESTS ===\n";
	DiamondTrap d1("D1");
	DiamondTrap d2;
	DiamondTrap d3(d1);
	d2 = d1;

	d1.attack("Boss");
	d1.takeDamage(20);
	d1.beRepaired(15);
	d1.guardGate();                 // ScavTrap ability
	d1.highFivesGuys();             // FragTrap ability
	d1.whoAmI();
	// d1.showStatus();
	// d2.showStatus();
	// d3.showStatus();

	std::cout << "\n=== EDGE CASES ===\n";
	d1.takeDamage(200);             // 0 HP
	d1.attack("NoEnergy");          // should report dead
	d1.beRepaired(50);              // repair while alive
	// d1.showStatus();
	ClapTrap* ptr = new DiamondTrap("Bob");
	ptr->showStatus();
	delete ptr;
	return 0;
}

