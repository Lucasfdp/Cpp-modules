/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:29:30 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/26 05:06:40 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;
	
public:
	Form();
	Form(std::string name, int toSign, int toExec);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getToSign() const;
	int					getToExec() const;
	
	void				beSigned(const Bureaucrat& b);

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);