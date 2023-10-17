/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:20:18 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/17 11:13:49 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl; // 6
	std::cout << a << std::endl;   // 6
	std::cout << a++ << std::endl; // 6
	std::cout << a << std::endl;   // 7

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
