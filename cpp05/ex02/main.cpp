/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:19:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/30 05:33:46 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//srand(time(NULL)); include in main for seeding
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime>   // time

int main()
{
	srand(time(NULL));
	std::cout << "=== BASIC EXECUTION TEST ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Marvin");

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ROBOTOMY RANDOMNESS TEST ===" << std::endl;
	try
	{
		Bureaucrat tech("Tech", 1);
		RobotomyRequestForm robot("Unit42");

		tech.signForm(robot);

		for (int i = 0; i < 5; i++)
		{
			std::cout << "Attempt " << i + 1 << ":" << std::endl;
			tech.executeForm(robot);
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== EXECUTION FAIL (NOT SIGNED) ===" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 1);
		ShrubberyCreationForm shrub("garden");

		worker.executeForm(shrub); // should fail (not signed)
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== EXECUTION FAIL (GRADE TOO LOW) ===" << std::endl;
	try
	{
		Bureaucrat low("Intern", 150);
		ShrubberyCreationForm shrub("park");

		low.signForm(shrub);      // might fail depending on required grade
		low.executeForm(shrub);   // should fail
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;

}
