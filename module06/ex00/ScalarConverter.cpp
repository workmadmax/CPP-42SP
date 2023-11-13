/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:56:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/13 12:02:49 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &) {};

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
};

// methods function convert

std::string	ScalarConverter::getType(std::string input)
{
	if (input.length() == 0)
		return ("empty");
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return ("char");
	else {
		char	*endptr = NULL;
		errno = 0;
		if (endptr == input.c_str() + input.length() && errno == 0)
			return ("int");
		else {
			endptr = NULL;
			errno = 0;
			std::strtod(input.c_str(), &endptr);
			if (endptr == input.c_str() + input.length() && errno == 0)
				return ("double");
			else {
				endptr = NULL;
				errno = 0;
				std::strtof(input.c_str(), &endptr);
				if (((endptr == input.c_str() + input.length())
					|| (endptr == input.c_str() + input.length() - 1
					&& input[input.length() - 1] == 'f'))
					&& errno == 0)
					return ("float");
				else
					return ("invalid");
			}
		}
	}
};

void	ScalarConverter::convert(const std::string input)
{
	std::string type = getType(input);
	
	if (type == "char") {
		char c = input[0];
		printChar(c);
	} else if (type == "int") {
		long l = std::atol(input.c_str());
		printInt(l);
	} else if (type == "float") {
		float f = std::atof(input.c_str());
		printFloat(f);
	} else if (type == "double") {
		double d = std::atof(input.c_str());
		printDouble(d);
	} else {
		if (errno)
			std::cout << "Error: " << strerror(errno) << std::endl;
		else
			std::cout << "Error: Invalid type: " + type << std::endl;
	}
};

// methods function print

void	printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
};

void	printInt(long i)
{
	char c = static_cast<char>(i);
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if ( std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
};

void	printFloat(float f)
{
	char c = static_cast<char>(f);
	if (std::isnan(f) || std::isinf(f) || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (std::isnan(f) || std::isinf(f) || f > (float)INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (std::isnan(f) || std::isinf(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
};

void	printDouble(double d)
{
	char c = static_cast<char>(d);
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::isnan(d) || std::isinf(d) || d > (double)INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (std::isnan(d) || std::isinf(d))
		std::cout << "float: " << d << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
	if (std::isnan(d) || std::isinf(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
};



