/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/16 23:52:12 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		
		void	makeSound() const;
		
		Dog();
		Dog(std::string type);
		Dog&	operator=(const Dog& other);
		Dog(const Dog &other);
		~Dog();
};

#endif