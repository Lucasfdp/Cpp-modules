/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 06:33:38 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/21 06:34:08 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	
		Cure();
		Cure(std::string const & type);
		Cure(const Cure &other);
		Cure&	operator=(const Cure& other);
		~Cure();
		
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif