/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:28:44 by luferna3          #+#    #+#             */
/*   Updated: 2026/03/30 05:44:34 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <exception>
#include "AForm.hpp"


class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

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
		
		void	incrementGrade();
		void	decrementGrade();
		int		getGrade() const;
		const std::string&	getName() const;
		void	signForm(AForm& f);
		void	executeForm(AForm const & form) const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint);