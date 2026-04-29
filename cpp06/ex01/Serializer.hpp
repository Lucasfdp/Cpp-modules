/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:12:31 by luferna3          #+#    #+#             */
/*   Updated: 2026/04/27 23:15:41 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <string>

struct Data {
    int value;
    std::string name;
};

class Serializer
{
	private:

		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};