/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:56:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/11 14:58:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
};

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		// this-> = other.;
	}
	return (*this);
};

void	ScalarConverter::convertChar(std::string str)
{
	char c;
	
	if (str.length() == 1)
	{
		c = str[0];
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
};

void	ScalarConverter::convertInt(std::string str)
{
	int i;
	
	i = std::atoi(str.c_str());
	if (i == 0 && str != "0")
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "char: ";
	if (isprint(i))
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Non displayable here" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	
};

void	ScalarConverter::convertFloat(std::string str)
{
	float f;
	
	f = std::atof(str.c_str());
	if (f >= -std::numeric_limits<float>::max() && f <= std::numeric_limits<float>::max())
	{
		std::cout << "char: ";
		if (isprint(f))
			std::cout << static_cast<char>(f) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (f >= INT_MIN && f <= INT_MAX)
			std::cout << static_cast<int>(f) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
};

void	ScalarConverter::convertDouble(std::string str)
{
	double d;
	
	d = std::atof(str.c_str());
	if (d >= -std::numeric_limits<double>::max() && d <= std::numeric_limits<double>::max())
	{
		std::cout << "char: ";
		if (isprint(d))
			std::cout << static_cast<char>(d) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (d >= INT_MIN && d <= INT_MAX)
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
			std::cout << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
};

void	ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		convertChar(str);
	else if (str.find('.') == std::string::npos)
		convertInt(str);
	else
	{
		if (str.find('f') != std::string::npos)
			str.erase(str.find('f'), 1);
		if (str.find('.') == str.rfind('.'))
			convertFloat(str);
		else
			convertDouble(str);
	}
};

// exceptions

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
};

const char* ScalarConverter::InvalidConversionException::what() const throw()
{
	return ("Invalid conversion");
};