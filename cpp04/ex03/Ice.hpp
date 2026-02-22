/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 06:14:45 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/21 06:34:25 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	
		Ice();
		Ice(std::string const & type);
		Ice(const Ice &other);
		Ice&	operator=(const Ice& other);
		~Ice();
		
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif