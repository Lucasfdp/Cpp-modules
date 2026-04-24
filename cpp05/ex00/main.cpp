/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:19:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/25 05:23:22 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== VALID CREATION ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade(); // should go to 1
		std::cout << "After increment: " << a << std::endl;

		a.decrementGrade(); // back to 2
		std::cout << "After decrement: " << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID CREATION (TOO HIGH) ===" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID CREATION (TOO LOW) ===" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== INCREMENT EDGE CASE ===" << std::endl;
	try
	{
		Bureaucrat d("Dave", 1);
		std::cout << d << std::endl;
		d.incrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== DECREMENT EDGE CASE ===" << std::endl;
	try
	{
		Bureaucrat e("Eve", 150);
		std::cout << e << std::endl;
		e.decrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
	try
	{
		Bureaucrat original("Frank", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;
	try
	{
		Bureaucrat a("Gina", 10);
		Bureaucrat b("Henry", 50);

		std::cout << "Before assignment:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;

		b = a;

		std::cout << "After assignment:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
