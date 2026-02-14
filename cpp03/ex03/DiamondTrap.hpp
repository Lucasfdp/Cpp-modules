/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 05:08:57 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:33:57 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
	
		std::string	_name;
	
	public:
	
		void	showStatus(void) const;
		void	whoAmI(void);
			
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap&	operator=(const DiamondTrap& other);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);
};

#endif