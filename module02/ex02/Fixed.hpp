/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:12:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/17 10:58:22 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

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