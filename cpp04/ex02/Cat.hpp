/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:36 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 03:20:18 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:

		Brain*	_Brain;
	
	public:
		
		void	makeSound() const;
		void	setBrainIdea(int index, const std::string& idea);
		std::string	getBrainIdea(int index) const;
		
		
		Cat();
		Cat(std::string type);
		Cat&	operator=(const Cat& other);
		Cat(const Cat &other);
		~Cat();
};

#endif