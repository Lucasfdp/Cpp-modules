/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 03:57:44 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/05 03:41:00 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{

}

Fixed::Fixed(int num)
{
	_rawBits = num * 256;
}

Fixed::Fixed(float num)
{
	_rawBits = roundf(num * 256);
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{

}

Fixed&	Fixed::operator=(const Fixed& other)
{
    if (this != &other)
		_rawBits = other._rawBits;
    return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (_rawBits / 256.0f);
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> 8);
}

//comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return (_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_rawBits != other._rawBits);
}

//Arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	tmp;
	
	tmp = (long long)this->_rawBits * (long long)other._rawBits;
	result.setRawBits(tmp >> _fractBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long	tmp;

	if (other._rawBits == 0)
	{
		std::cout << "HahAHAhaHaHahAHA yOu TRy mAKE a SiLlY oN Me buT i mAkE A sIlLY ON YoU" << std::endl;
		return (Fixed());
	}
	tmp = ((long long)this->_rawBits << _fractBits) / (long long)other._rawBits;
	result.setRawBits(tmp);
	return (result);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_rawBits++;
	return (tmp);
}

Fixed& Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_rawBits--;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}

Fixed::~Fixed()
{

}