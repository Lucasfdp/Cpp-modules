/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:58:50 by luferna3          #+#    #+#             */
/*   Updated: 2026/02/05 20:02:53 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const& a, Point const& b, Point const& c, Point const& p, std::string label)
{
	std::cout << label << ": ";
	if (bsp(a, b, c, p))
		std::cout << "INSIDE";
	else
		std::cout << "OUTSIDE";
	std::cout << std::endl;
}

int main(void)
{
	// Define a simple triangle
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	// === Normal cases ===
	test(a, b, c, Point(1, 1), "Inside (center)");
	test(a, b, c, Point(2, 3), "Inside (random)");
	test(a, b, c, Point(5, 2), "Inside (near edge)");

	// === Outside cases ===
	test(a, b, c, Point(-1, 1), "Outside (left)");
	test(a, b, c, Point(1, -1), "Outside (bottom)");
	test(a, b, c, Point(10, 10), "Outside (far)");

	// === Edge cases (must be OUTSIDE per subject) ===
	test(a, b, c, Point(0, 0), "Vertex A");
	test(a, b, c, Point(5, 0), "On edge AB");
	test(a, b, c, Point(0, 5), "On edge AC");
	test(a, b, c, Point(5, 5), "On hypotenuse");

	return 0;
}
