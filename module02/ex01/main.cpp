/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:56:41 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/16 13:00:41 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// color

const std::string	red("\033[0;31m");
const std::string	green("\033[0;32m");
const std::string	yellow("\033[0;33m");
const std::string	reset("\033[0m");

int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << green;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << reset;
	
	std::cout << yellow;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << reset;
	
	return (0);
}