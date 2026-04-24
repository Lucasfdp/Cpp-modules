/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 05:29:46 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/30 05:55:03 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void	ShrubberyCreationForm::ex_action() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	
	if (!file)
		return ;

	file << "       /\\\n";
	file << "      /**\\\n";
	file << "     /****\\\n";
	file << "    /******\\\n";
	file << "   /********\\\n";
	file << "  /**********\\\n";
	file << " /************\\\n";
	file << "/**************\\\n";
	file << "      ||||\n";
	file << "      ||||\n";
}