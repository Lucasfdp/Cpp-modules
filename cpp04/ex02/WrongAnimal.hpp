/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:04:16 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 00:22:04 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:

		std::string	_type;

	public:
		
		void	makeSound() const;
		void	setType(const std::string &value);
		std::string	getType(void) const;
		
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal&	operator=(const WrongAnimal& other);
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();
};

#endif