/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 03:42:00 by luferna3          #+#    #+#             */
/*   Updated: 2026/05/06 04:48:38 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

// swap
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// min
template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

// max
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}