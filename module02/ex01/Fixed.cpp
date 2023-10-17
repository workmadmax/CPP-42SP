/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:54:41 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/17 11:24:24 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	
	std::cout << green << "Default constructor called" << std::endl;
	std::cout << reset;
}

Fixed::Fixed(const int value)
{
	std::cout << blue << "Int constructor called" << std::endl;
	std::cout << reset;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << yellow << "Float constructor called" << std::endl;
	std::cout << reset;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << orange << "Copy constructor called" << std::endl;
	std::cout << reset;
	_value = fixed.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor called" << std::endl;
	std::cout << reset;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}