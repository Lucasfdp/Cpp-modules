/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:29:30 by luferna3          #+#    #+#             */
/*   Updated: 2026/04/25 01:32:09 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;
	
public:
	AForm();
	AForm(std::string name, int toSign, int toExec);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getToSign() const;
	int					getToExec() const;
	
	void				beSigned(const Bureaucrat& b);
	void				execute(const Bureaucrat& b) const;
	virtual void		ex_action() const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Grade too high";
			}
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Grade too low";
			}
	};
	
	class UnsignedFormException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Form has not been signed";
			}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);