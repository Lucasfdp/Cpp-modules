/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:00 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:24:02 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* animals[4];

//     animals[0] = new Dog();
//     animals[1] = new Cat();
//     animals[2] = new Dog("Steve");
//     animals[3] = new Cat("Mia");

//     for (int i = 0; i < 4; i++)
//     {
//         std::cout << animals[i]->getType() << " says ";
//         animals[i]->makeSound();
//     }

//     for (int i = 0; i < 4; i++)
//         delete animals[i];

//     return 0;
// }

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const Animal* j = new Dog();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();

	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}
