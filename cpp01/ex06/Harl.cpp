/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 05:02:24 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/13 03:17:46 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

Level	getLevel(std::string input)
{
	if (input == "DEBUG")
		return (DEBUG);
	else if (input == "INFO")
		return (INFO);
	else if (input == "WARNING")
		return (WARNING);
	else if (input == "ERROR")
		return (ERROR);
	return (UNKNOWN);
}

void Harl::filter(std::string levelStr)
{
    Level level = getLevel(levelStr);

    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	switch (level)
	{
		case DEBUG:
			(this->*functions[DEBUG])();
			/* fall through */
		case INFO:
			(this->*functions[INFO])();
			/* fall through */
		case WARNING:
			(this->*functions[WARNING])();
			/* fall through */
		case ERROR:
			(this->*functions[ERROR])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					<< std::endl;
			break;
	}
}

Harl::~Harl()
{
	
}