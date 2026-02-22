/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:26:27 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/17 02:24:43 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:

		std::string _ideas[100];
		
	public:

		void	setIdea(int index, const std::string &idea);
		const std::string	getIdea(int index) const;
		const std::string*	getAllIdeas(void) const;

		Brain();
		Brain(const std::string ideas[], int amount);
		Brain&	operator=(const Brain& other);
		Brain(const Brain &other);
		~Brain();
};

#endif

