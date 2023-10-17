/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:12:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/17 11:25:56 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

const std::string	red("\033[0;31m");
const std::string	green("\033[0;32m");
const std::string	yellow("\033[0;33m");
const std::string	blue("\033[0;34m");
const std::string	orange("\033[0;38;5;208m");
const std::string 	pink("\033[0;38;5;13m");
const std::string 	reset("\033[0m");

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed	&operator=(const Fixed &fixed);

	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;

	Fixed	operator+(const Fixed &fixed) const;
	Fixed	operator-(const Fixed &fixed) const;
	Fixed	operator*(const Fixed &fixed) const;
	Fixed	operator/(const Fixed &fixed) const;

	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);

	static	Fixed	&max(Fixed &a, Fixed &b);
	static	Fixed	&min(Fixed &a, Fixed &b);
	
	static	Fixed	const	&max(Fixed const &a, Fixed const &b);
	static	Fixed	const	&min(Fixed const &a, Fixed const &b);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);