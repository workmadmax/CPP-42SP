/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:12:38 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/16 09:57:57 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// colors 
const std::string	red("\033[0;31m");
const std::string	green("\033[0;32m");
const std::string	yellow("\033[0;33m");
const std::string	blue("\033[0;34m");
const std::string	orange("\033[0;38;5;208m");
const std::string 	reset("\033[0m");


class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();

	Fixed	&operator=(const Fixed &f);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};