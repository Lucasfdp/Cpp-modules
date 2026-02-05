/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:18:51 by luferna3          #+#    #+#             */
/*   Updated: 2026/01/01 04:11:33 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string 	string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string&	stringREF = string;

	//Addresses:
	std::cout << "ADDRESSES" << std::endl;
	std::cout << "String: " << &string << "\n"
	<< "Pointer: " << stringPTR << "\n"
	<< "Reference: " << &stringREF << std::endl;
	
	//Values:
	std::cout << "VALUES" << std::endl;
	std::cout << "String: " << string << "\n"
	<< "Pointer: " << *stringPTR << "\n"
	<< "Reference: " << stringREF << std::endl;
	return 0;
}
