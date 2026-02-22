/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:17:39 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:

		Brain*	_Brain;
	
	public:
		
		void	makeSound() const;
		void	setBrainIdea(int index, const std::string& idea);
		std::string	getBrainIdea(int index) const;
		
		
		Dog();
		Dog(std::string type);
		Dog&	operator=(const Dog& other);
		Dog(const Dog &other);
		~Dog();
};

#endif