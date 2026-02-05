/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 04:22:56 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/03 05:40:54 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		const std::string&	getType();
		void				setType(const std::string& newWeapon);
		
	Weapon(std::string type);
	~Weapon(void);
};

#endif