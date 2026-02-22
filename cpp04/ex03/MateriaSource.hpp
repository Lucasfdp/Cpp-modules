/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:19:33 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/21 08:53:26 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria*	_templates[4];
		
	public:
	
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource&	operator=(const MateriaSource &other);
		~MateriaSource();
		
		void learnMateria(AMateria* newMat);
		AMateria* createMateria(std::string const & type);
};

#endif