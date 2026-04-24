/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:19:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/26 05:13:00 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== VALID SETUP ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		Form taxForm("TaxForm", 60, 30);
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== SIGN FAIL (GRADE TOO LOW) ===" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 100);
		Form contract("Contract", 50, 20);

		std::cout << jim << std::endl;
		jim.signForm(contract);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== FORM CONSTRUCTOR FAIL ===" << std::endl;
	try
	{
		Form badForm("BadForm", 0, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== BUREAUCRAT CONSTRUCTOR FAIL ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== EDGE CASE: SIGN TWICE ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 10);
		Form permit("Permit", 20, 10);

		alice.signForm(permit);
		alice.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== COPY & ASSIGNMENT ===" << std::endl;
	try
	{
		Bureaucrat a("A", 42);
		Bureaucrat b(a);
		Bureaucrat c("C", 10);

		c = a;

		std::cout << "A: " << a << std::endl;
		std::cout << "B (copy): " << b << std::endl;
		std::cout << "C (assigned): " << c << std::endl;

		Form f1("F1", 30, 10);
		Form f2(f1);
		Form f3("F3", 100, 100);

		f3 = f1;

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;

}
