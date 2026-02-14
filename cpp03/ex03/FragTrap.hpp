/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 02:54:48 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/14 04:48:04 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	
		void	showStatus() const;
		void	highFivesGuys(void);
		
		FragTrap();
		FragTrap(std::string name);
		FragTrap&	operator=(const FragTrap& other);
		FragTrap(const FragTrap &other);
		~FragTrap();
};

#endif