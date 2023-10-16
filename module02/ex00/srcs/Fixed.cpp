/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:12:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/16 10:01:13 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << green << "Default constructor called" << std::endl;
	std::cout << reset;
}

Fixed::Fixed(const Fixed &f) : _value(f._value)
{
	std::cout << yellow << "Copy constructor called" << std::endl;
	std::cout << reset;
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor called" << std::endl;
	std::cout << reset;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << orange << "Copy assignment operator called" << std::endl;
	std::cout << reset;
	if (this != &f)
		return (*this);
	_value = f.getRawBits();
	return (*this);
}

/// @brief Return the raw value of the fixed point value.
/// @return The raw value of the fixed point value.
int		Fixed::getRawBits(void) const
{
	std::cout << blue << "getRawBits member function called" << std::endl;
	std::cout << reset;
	return (_value);
}


/// @brief Define the raw value of the fixed point value.
/// @param raw The raw value of the fixed point value.
void	Fixed::setRawBits(int const raw)
{
	std::cout << blue << "setRawBits member function called" << std::endl;
	std::cout << reset;
	this->_value = raw;
}