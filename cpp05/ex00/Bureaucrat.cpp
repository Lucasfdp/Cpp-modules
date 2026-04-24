/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:28:26 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/25 05:14:34 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw (GradeTooLowException());
	_grade++;
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << ".";
	return (os);
}
