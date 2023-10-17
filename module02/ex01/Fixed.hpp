/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:54:47 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/16 12:55:37 by madmax42         ###   ########.fr       */
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
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);