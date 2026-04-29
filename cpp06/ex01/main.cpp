/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:13:58 by luferna3          #+#    #+#             */
/*   Updated: 2026/04/27 23:17:33 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data;
    data.value = 42;
    data.name = "Lucas";

    // Original pointer
    Data* originalPtr = &data;

    // Serialize
    uintptr_t raw = Serializer::serialize(originalPtr);

    // Deserialize
    Data* deserializedPtr = Serializer::deserialize((uintptr_t)raw);

    // Print addresses
    std::cout << "Original pointer:      " << originalPtr << std::endl;
    std::cout << "Deserialized pointer:  " << deserializedPtr << std::endl;

    // Check if they match
    if (originalPtr == deserializedPtr)
        std::cout << "✅ Success: Pointers match!" << std::endl;
    else
        std::cout << "❌ Error: Pointers do not match!" << std::endl;

    // Optional: show that data is still accessible
    std::cout << "Data value: " << deserializedPtr->value << std::endl;
    std::cout << "Data name:  " << deserializedPtr->name << std::endl;

    return 0;
}

