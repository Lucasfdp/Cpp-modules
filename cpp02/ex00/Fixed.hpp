/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:32:34 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/16 04:25:46 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int _rawBits;
	static const int	_fractBits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif