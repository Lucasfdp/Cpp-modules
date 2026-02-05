/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:56:39 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/05 20:02:26 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/// @brief Function to determine where a point finds itself relative to two triangle vertexes
/// @param p1 Point
/// @param v1 Vertex 1
/// @param v2 Vertex 2
/// @return A negative or Positive Fixed number
static Fixed	sign(Point const& p1, Point const& v1, Point const& v2)
{
	return ((p1.getX() - v2.getX()) * (v1.getY() - v2.getY())
	       - (v1.getX() - v2.getX()) * (p1.getY() - v2.getY()));
}

/// @brief Function to determine whether a point is inside a triangle
/// @param a Vertex 1 of triangle
/// @param b Vertex 2 of triangle
/// @param c Vertex 3 of triangle
/// @param point Point to test
/// @return True if the point is inside and false if it is outside or on the line
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	// These will be a mix of positive and negative numbers depending on the triangles and points tested
	
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false); // Edge cases like vertexes or on the line points
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0); // Will return true if any of the numbers are negative
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0); // Will return true if any of the numbers are positive

	return (!(has_neg && has_pos)); // Needs 1 true and 1 false to return true
}
