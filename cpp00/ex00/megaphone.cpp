/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 06:23:36 by luferna3          #+#    #+#             */
/*   Updated: 2025/12/28 06:23:37 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

void megaphone(const std::string &input)
{
	std::string	output;

	for (size_t i = 0; i < input.length(); i++)
	{
		output += std::toupper(static_cast<unsigned char>(input[i]));
	}
	std::cout << output << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string input = "";
	for (int i = 1; i < ac; i++)
	{
		input += av[i];
		if (i < ac - 1)
			input += " ";
	}
	megaphone(input);
	return 0;
}
