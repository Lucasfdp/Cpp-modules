/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 05:31:08 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/26 21:57:20 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// int main()
// {
// 	MateriaSource src;
// 	AMateria*	tmp;
// 	tmp = new Ice();
// 	src.learnMateria(tmp);
// 	delete tmp;
		
// 	tmp = new Cure();
// 	src.learnMateria(tmp);
// 	delete tmp;

// 	Character alice("Alice");
// 	Character bob("Bob");

// 	AMateria* ice1 = src.createMateria("ice");
// 	AMateria* cure1 = src.createMateria("cure");

// 	alice.equip(ice1);
// 	alice.equip(cure1);

// 	alice.use(0, bob);
// 	alice.use(1, bob);

// 	// Unequip before deleting manually
// 	alice.unequip(0);
// 	alice.unequip(1);

// 	delete ice1;
// 	delete cure1;

// 	return 0;
// }

int main()
{
    std::cout << "===== Creating MateriaSource =====" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());

    std::cout << "\n===== Creating Characters =====" << std::endl;
    Character alice("Alice");
    Character bob("Bob");

    std::cout << "\n===== Creating Materias =====" << std::endl;
    AMateria* m1 = src.createMateria("ice");
    AMateria* m2 = src.createMateria("cure");
    AMateria* m3 = src.createMateria("ice");
    AMateria* m4 = src.createMateria("cure");
    AMateria* m5 = src.createMateria("ice"); // will test full inventory

    std::cout << "\n===== Equipping Alice =====" << std::endl;
    alice.equip(m1);
    alice.equip(m2);
    alice.equip(m3);
    alice.equip(m4);
    alice.equip(m5); // should say inventory full

    std::cout << "\n===== Using Materias =====" << std::endl;
    alice.use(0, bob);
    alice.use(1, bob);
    alice.use(2, bob);
    alice.use(3, bob);
    alice.use(42, bob); // invalid index
    alice.use(-1, bob); // invalid index

    std::cout << "\n===== Unequip Test =====" << std::endl;
    alice.unequip(2); // remove m3
    alice.use(2, bob); // should do nothing

    std::cout << "\n===== Manual delete of unequipped materia =====" << std::endl;
    delete m3; // caller handles deletion

    std::cout << "\n===== Deep Copy Constructor Test =====" << std::endl;
    Character copyAlice(alice);
    copyAlice.use(0, bob);
    copyAlice.use(1, bob);

    std::cout << "\n===== Assignment Operator Test =====" << std::endl;
    Character tmp("Temp");
    tmp = alice;
    tmp.use(0, bob);
    tmp.use(1, bob);

    std::cout << "\n===== Unknown Materia Test =====" << std::endl;
    AMateria* unknown = src.createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia not created (correct)" << std::endl;

    std::cout << "\n===== Cleanup =====" << std::endl;

    // Unequip remaining materias before manual delete
    alice.unequip(0);
	delete m1;

	alice.unequip(1);
	delete m2;

	alice.unequip(2); // if previously unequipped already, skip
	alice.unequip(3);
	delete m4;

	// m5 was never equipped (inventory full)
	delete m5;


    std::cout << "\n===== End of Program =====" << std::endl;
    return 0;
}
