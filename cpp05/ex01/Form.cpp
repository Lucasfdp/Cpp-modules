/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:52:53 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/26 05:09:39 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _toSign(150), _toExec(150)
{
	
}

Form::Form(std::string name, int toSign, int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec)
{
	if (_toExec < 1 || _toSign < 1)
		throw (GradeTooHighException());
	if (_toExec > 150 || _toSign > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& other) : _name(other.getName()), _signed(other.getSigned()), _toSign(other.getToSign()), _toExec(other.getToExec())
{
	
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

Form::~Form()
{
	
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getToSign() const
{
	return (_toSign);
}

int	Form::getToExec() const
{
	return (_toExec);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _toSign)
		throw (GradeTooLowException());
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName()
	<< "\nSigned: " << f.getSigned()
	<< "\nGrade to sign: " << f.getToSign()
	<< "\nGrade to execute: " << f.getToExec();
	
	return (os);
}