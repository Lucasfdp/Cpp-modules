/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:48 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/13 03:12:53 by luferna3         ###   ########.fr       */
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
		void	showStatus() const;
		void	guardGate();
		
		bool	getGM(void) const;
		void	setGM(const bool &value);
		
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap&	operator=(const ScavTrap& other);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
};

#endif