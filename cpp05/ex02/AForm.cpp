/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:52:53 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/30 02:07:55 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _toSign(150), _toExec(150)
{
	
}

AForm::AForm(std::string name, int toSign, int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec)
{
	if (_toExec < 1 || _toSign < 1)
		throw (GradeTooHighException());
	if (_toExec > 150 || _toSign > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& other) : _name(other.getName()), _signed(other.getSigned()), _toSign(other.getToSign()), _toExec(other.getToExec())
{
	
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

AForm::~AForm()
{
	
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getToSign() const
{
	return (_toSign);
}

int	AForm::getToExec() const
{
	return (_toExec);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _toSign)
		throw (GradeTooLowException());
	_signed = true;
}

void	AForm::execute(const Bureaucrat& b) const
{
	if (!_signed)
		throw (UnsignedFormException());
	if (b.getGrade() > _toExec)
		throw (GradeTooLowException());
	ex_action();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form: " << f.getName()
	<< "\nSigned: " << f.getSigned()
	<< "\nGrade to sign: " << f.getToSign()
	<< "\nGrade to execute: " << f.getToExec();
	
	return (os);
}