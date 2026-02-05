/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:50:29 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/01 04:42:54 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
	
		void	announce(void);
		void	setName(const std::string &name);

		Zombie();
		~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif