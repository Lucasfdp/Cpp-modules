/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:21:05 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/13 04:35:58 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
		
	public:
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	showStatus() const;
		
		std::string	getName() const;
		unsigned int	getHP() const;
		unsigned int	getEP() const;
		unsigned int	getAD() const;

		void	setName(const std::string &value);
		void	setHP(const unsigned int &value);
		void	setEP(const unsigned int &value);
		void	setAD(const unsigned int &value);
		
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap&	operator=(const ClapTrap& other);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();
};


#endif