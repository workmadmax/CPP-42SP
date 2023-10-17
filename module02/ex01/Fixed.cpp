/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:54:41 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/16 13:02:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = fixed.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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