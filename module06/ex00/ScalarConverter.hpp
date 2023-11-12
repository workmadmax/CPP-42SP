/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:46:09 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 10:43:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include <climits>
#include <cmath>
#include <cerrno>

/*
Write a static class ScalarConverter that will contain a method "convert" takes as
parameter a string representation of a C++ literal in its most common form.
This literal must belong to one of the following types: char, int, float or double.

Expect for char parameters, only the decimal notation will be used.

Examples of char literals: 'c', 'a', ....
	To make things simple, please note that non dysplay characters shouldn't
	be used as inputs. If a conversion to char is not displayed, prints an
	informatuve message.

Examples of int literals: 0, -42, 42....

Examples of float literals: 0.0f, -4.2f, 4.2f...
	You have to handle these pseudo literals as well (you know, for science):
		nanf, -nanf, inff, -inff.

Examples of double literals: 0.0, -4.2, 4.2...
	You have to handle these pseudo literals as well (you know, for science):
		nan, -nan, inf, -inf.
*/
class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter	&operator=(const ScalarConverter& other);
public:
	~ScalarConverter();
	static void convert(std::string input);
	static std::string getType(std::string input);
};