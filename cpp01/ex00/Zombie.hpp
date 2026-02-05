/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 03:58:19 by luferna3          #+#    #+#             */
/*   Updated: 2025/12/30 04:35:50 by luferna3         ###   ########.fr       */
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
		
		Zombie(std::string newName);
		~Zombie(void);
};

void	randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif