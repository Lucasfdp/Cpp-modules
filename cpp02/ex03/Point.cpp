/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 03:56:12 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/05 18:55:42 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{

}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
	
}


Fixed Point::getX() const
{
	return (_x);
}


Fixed Point::getY() const
{
	return (_y);
}

