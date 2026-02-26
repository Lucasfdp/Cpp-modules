/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 05:30:58 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/26 22:05:56 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria& operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const & getType() const;
    void setType(const std::string &newType);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
