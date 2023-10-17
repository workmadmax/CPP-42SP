/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:16:21 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/17 11:19:10 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors

Fixed::Fixed(void) : _value(0)
{
	
};

Fixed::Fixed(const int value)
{
	this->_value = value << this->_fractionalBits;
};

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_fractionalBits));
};

Fixed::Fixed(const Fixed &Fixed)
{
	*this = Fixed;
};

Fixed::~Fixed(void)
{

};

// function methods

int		Fixed::getRawBits(void) const
{
	return (this->_value);
};

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
};

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
};

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
};

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	this->_value = fixed.getRawBits();
	return (*this);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
};

// operators comparision

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_value == fixed._value);
};

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_value != fixed._value);
};

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_value > fixed._value);
};

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_value < fixed._value);
};

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_value >= fixed._value);
};

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_value >= fixed._value);
};

// operators arithmetics

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
};

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
};

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
};

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	if (fixed.toFloat() == 0)
	{
		std::cout << "Error: division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / fixed.toFloat()));
};

// operators increment/decrement

Fixed	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
};

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	
	this->_value++;
	return (tmp);
};

Fixed	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
};

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	
	this->_value--;
	return (tmp);
};

// min/max

Fixed	&Fixed::max(Fixed &obj, Fixed &obj2)
{
	if (obj2._value > obj._value)
		return (obj2);
	return (obj);
};

Fixed const	&Fixed::max(const Fixed &obj, const Fixed &obj2)
{
	if (obj2._value > obj._value)
		return (obj2);
	return (obj);
};

Fixed	&Fixed::min(Fixed &obj, Fixed &obj2)
{
	if (obj2._value < obj._value)
		return (obj2);
	return (obj);
};

Fixed const	&Fixed::min(const Fixed &obj, const Fixed &obj2)
{
	if (obj2._value < obj._value)
		return (obj2);
	return (obj);
};