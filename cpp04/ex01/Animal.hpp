/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:41 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 04:03:45 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:

		std::string	_type;

	public:
		
		virtual void	makeSound() const;
		void	setType(const std::string &value);
		std::string	getType(void) const;
		
		Animal();
		Animal(std::string type);
		Animal&	operator=(const Animal& other);
		Animal(const Animal &other);
		virtual ~Animal();
};

#endif