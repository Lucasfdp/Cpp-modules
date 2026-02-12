/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:48 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/12 06:12:05 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	bool	_guardMode;
		
	public:
	
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	showStatus() const;
		void	guardGate();
		
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap&	operator=(const ScavTrap& other);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
};

#endif