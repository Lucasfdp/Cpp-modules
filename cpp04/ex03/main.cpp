/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 05:31:08 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/22 06:02:14 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	MateriaSource src;
	AMateria*	tmp;
	tmp = new Ice();
	src.learnMateria(tmp);
	delete tmp;
		
	tmp = new Cure();
	src.learnMateria(tmp);
	delete tmp;

	Character alice("Alice");
	Character bob("Bob");

	AMateria* ice1 = src.createMateria("ice");
	AMateria* cure1 = src.createMateria("cure");

	alice.equip(ice1);
	alice.equip(cure1);

	alice.use(0, bob);
	alice.use(1, bob);

	// Unequip before deleting manually
	alice.unequip(0);
	alice.unequip(1);

	delete ice1;
	delete cure1;

	return 0;
}
