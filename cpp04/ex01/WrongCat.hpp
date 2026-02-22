/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:07:04 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 00:08:25 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		
		void	makeSound() const;
		
		WrongCat();
		WrongCat(std::string type);
		WrongCat&	operator=(const WrongCat& other);
		WrongCat(const WrongCat &other);
		~WrongCat();
};

#endif