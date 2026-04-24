/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:19:49 by luferna3          #+#    #+#             */
/*   Updated: 2026/04/25 01:30:53 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//srand(time(NULL)); include in main for seeding
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

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

		worker.executeForm(shrub);
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

		low.signForm(shrub);
		low.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== INTERN: VALID FORM CREATION ===" << std::endl;
	{
		Intern bob;
		Bureaucrat boss("Boss", 1);

		AForm *f1 = bob.makeForm("shrubbery creation", "garden");
		AForm *f2 = bob.makeForm("robotomy request", "Bender");
		AForm *f3 = bob.makeForm("presidential pardon", "Marvin");

		if (f1) { boss.signForm(*f1); boss.executeForm(*f1); delete f1; }
		if (f2) { boss.signForm(*f2); boss.executeForm(*f2); delete f2; }
		if (f3) { boss.signForm(*f3); boss.executeForm(*f3); delete f3; }
	}

	std::cout << "\n=== INTERN: UNKNOWN FORM TYPE ===" << std::endl;
	{
		Intern bob;
		AForm *f = bob.makeForm("coffee request", "kitchen");
		if (f)
			delete f;
	}

	std::cout << "\n=== INTERN: FORM USED BY LOW GRADE BUREAUCRAT ===" << std::endl;
	{
		Intern bob;
		Bureaucrat low("Lowly", 150);

		AForm *f = bob.makeForm("presidential pardon", "someone");
		if (f)
		{
			low.signForm(*f);
			low.executeForm(*f);
			delete f;
		}
	}

	return 0;
}
