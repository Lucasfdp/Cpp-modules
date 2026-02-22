/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:36 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/16 23:32:56 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		
		void	makeSound() const;
		
		Cat();
		Cat(std::string type);
		Cat&	operator=(const Cat& other);
		Cat(const Cat &other);
		~Cat();
};

#endif